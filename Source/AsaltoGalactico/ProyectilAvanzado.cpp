// Fill out your copyright notice in the Description page of Project Settings.


#include "ProyectilAvanzado.h"
#include "GameFramework/ProjectileMovementComponent.h"


AProyectilAvanzado::AProyectilAvanzado()
{
    // El proyectil avanzado causa más daño
    Danio = 40.0f;

    // Aumentar la velocidad del proyectil
    if (ProjectileMovement != nullptr)
    {
        ProjectileMovement->InitialSpeed = 4000.0f;
        ProjectileMovement->MaxSpeed = 4000.0f;
    }

   /* // Cargar el modelo 3D del misil
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaMisil(
        TEXT("/Game/NavesEnemigos/aim_120b_amraam.aim_120b_amraam")
    );

    if (MallaMisil.Succeeded())
    {
        ProjectileMesh->SetStaticMesh(MallaMisil.Object);

        // Reducir el tamaño del misil
        ProjectileMesh->SetRelativeScale3D(
            FVector(0.15f, 0.15f, 0.15f)
        );
    }*/
}