// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"



// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Crear la malla del enemigo
	MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(
		TEXT("MallaEnemigo")
	);
    RootComponent = MallaEnemigo;

    // Configurar las colisiones
    MallaEnemigo->SetCollisionEnabled(
        ECollisionEnabled::QueryAndPhysics
    );

    MallaEnemigo->SetCollisionObjectType(ECC_WorldDynamic);

    MallaEnemigo->SetCollisionResponseToAllChannels(ECR_Block);

    // Vida inicial
    Vida = 100.0f;
    Velocidad = 0.0f;

    // Cargar una malla basica del contenido de Unreal
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaCargada(
        TEXT("/Game/NavesEnemigos/StarSparrow01.StarSparrow01")
    );

    if (MallaCargada.Succeeded())
    {
        MallaEnemigo->SetStaticMesh(MallaCargada.Object);
    }

    // Darle una forma inicial al enemigo
    MallaEnemigo->SetWorldScale3D(FVector(0.15f, 0.15f, 0.15f));

    MallaEnemigo->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    // Si la velocidad es cero, el enemigo no se mueve
    if (Velocidad <= 0.0f)
    {
        return;
    }

    // Mover al enemigo hacia adelante
    FVector Desplazamiento = FVector(1.0f, 0.0f, 0.0f)
        * Velocidad * DeltaTime;

    AddActorWorldOffset(Desplazamiento, true);

}

void AEnemigo::RecibirImpacto(float Danio)
{
    if (Danio <= 0.0f)
    {
        return;
    }

    if (Vida <= 0.0f)
    {
        return;
    }

    Vida -= Danio;

    if (Vida <= 0.0f)
    {
        Vida = 0.0f;

        // Avisar a los observadores antes de destruir el enemigo
        NotificarDestruccion();

        Destroy();
    }
}
float AEnemigo::ObtenerVida() const
{
    return Vida;
}

bool AEnemigo::EstaDestruido() const
{
    return Vida <= 0.0f;
}

float AEnemigo::ObtenerVelocidad() const
{
    return Velocidad;
}
void AEnemigo::ConfigurarVida(float NuevaVida)
{
    Vida = FMath::Max(0.0f, NuevaVida);
}

void AEnemigo::ConfigurarVelocidad(float NuevaVelocidad)
{
    Velocidad = FMath::Max(0.0f, NuevaVelocidad);
}

void AEnemigo::AgregarObservador(ObservadorEnemigo* Observador)
{
    if (Observador != nullptr)
    {
        Observadores.AddUnique(Observador);
    }
}

void AEnemigo::NotificarDestruccion()
{
    for (ObservadorEnemigo* Observador : Observadores)
    {
        if (Observador != nullptr)
        {
            Observador->NotificarEnemigoDestruido();
        }
    }
}