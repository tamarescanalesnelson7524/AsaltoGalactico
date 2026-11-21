// Copyright Epic Games, Inc. All Rights Reserved.

#include "AsaltoGalacticoProjectile.h"
#include "Enemigo.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AAsaltoGalacticoProjectile::AAsaltoGalacticoProjectile()
{
    // Cargar la malla del misil AMRAAM
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(
        TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile")
    );

    // Crear el componente visual
    ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(
        TEXT("ProjectileMesh0")
    );

    RootComponent = ProjectileMesh;

    if (ProjectileMeshAsset.Succeeded())
    {
        ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
    }

    // Configurar colisiones
    ProjectileMesh->SetCollisionProfileName(TEXT("Projectile"));

    ProjectileMesh->SetCollisionEnabled(
        ECollisionEnabled::QueryAndPhysics
    );

    ProjectileMesh->SetNotifyRigidBodyCollision(true);

    // Registrar evento de impacto
    ProjectileMesh->OnComponentHit.AddDynamic(
        this,
        &AAsaltoGalacticoProjectile::OnHit
    );

    // Crear componente de movimiento
    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(
        TEXT("ProjectileMovement0")
    );

    ProjectileMovement->UpdatedComponent = ProjectileMesh;
    ProjectileMovement->InitialSpeed = 3000.0f;
    ProjectileMovement->MaxSpeed = 3000.0f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->bShouldBounce = false;
    ProjectileMovement->ProjectileGravityScale = 0.0f;

    // Tiempo de vida del proyectil
    InitialLifeSpan = 3.0f;

    // Danio del proyectil
    Danio = 25.0f;
}

void AAsaltoGalacticoProjectile::OnHit(
    UPrimitiveComponent* HitComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    FVector NormalImpulse,
    const FHitResult& Hit
)
{
    if (OtherActor == nullptr || OtherActor == this)
    {
        return;
    }

    AEnemigo* EnemigoImpactado = Cast<AEnemigo>(OtherActor);

    if (EnemigoImpactado != nullptr)
    {
        UE_LOG(LogTemp, Warning,
            TEXT("DANIO DEL PROYECTIL: %f"), Danio);

        UE_LOG(LogTemp, Warning,
            TEXT("VIDA ANTES DEL IMPACTO: %f"),
            EnemigoImpactado->ObtenerVida());

        EnemigoImpactado->RecibirImpacto(Danio);

        UE_LOG(LogTemp, Warning,
            TEXT("VIDA DESPUES DEL IMPACTO: %f"),
            EnemigoImpactado->ObtenerVida());
    }

    Destroy();
}