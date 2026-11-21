// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsaltoGalacticoProjectile.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;

UCLASS(config = Game)
class ASALTOGALACTICO_API AAsaltoGalacticoProjectile : public AActor
{
    GENERATED_BODY()

protected:

    // Malla y colision del proyectil
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile)
    UStaticMeshComponent* ProjectileMesh;

    // Movimiento del proyectil
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
    UProjectileMovementComponent* ProjectileMovement;

    // Danio que provoca el proyectil
    UPROPERTY(EditDefaultsOnly, Category = Projectile)

    float Danio;

public:

    AAsaltoGalacticoProjectile();

    // Funcion que detecta el impacto
    UFUNCTION()
    void OnHit(
        UPrimitiveComponent* HitComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        FVector NormalImpulse,
        const FHitResult& Hit
    );

    // Obtener la malla del proyectil
    FORCEINLINE UStaticMeshComponent* GetProjectileMesh() const
    {
        return ProjectileMesh;
    }

    // Obtener el componente de movimiento
    FORCEINLINE UProjectileMovementComponent* GetProjectileMovement() const
    {
        return ProjectileMovement;
    }
};

