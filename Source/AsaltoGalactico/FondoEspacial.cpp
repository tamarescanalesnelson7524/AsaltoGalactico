// Fill out your copyright notice in the Description page of Project Settings.


#include "FondoEspacial.h"

#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"

// Sets default values
AFondoEspacial::AFondoEspacial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    // Crear el plano del fondo
    MallaFondo = CreateDefaultSubobject<UStaticMeshComponent>(
        TEXT("MallaFondo")
    );

    RootComponent = MallaFondo;

    // Cargar el plano básico de Unreal
    static ConstructorHelpers::FObjectFinder<UStaticMesh> Plano(
        TEXT("/Engine/BasicShapes/Plane.Plane")
    );

    if (Plano.Succeeded())
    {
        MallaFondo->SetStaticMesh(Plano.Object);
    }

    // Cargar el material espacial
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialEspacial(
        TEXT("/Game/FondoGalactico/M_Espacio.M_Espacio")
    );

    if (MaterialEspacial.Succeeded())
    {
        MallaFondo->SetMaterial(0, MaterialEspacial.Object);
    }

    // Aumentar el tamaño del fondo
    MallaFondo->SetRelativeScale3D(FVector(40.0f, 40.0f, 1.0f));

    // El fondo no necesita colisiones
    MallaFondo->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void AFondoEspacial::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFondoEspacial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

