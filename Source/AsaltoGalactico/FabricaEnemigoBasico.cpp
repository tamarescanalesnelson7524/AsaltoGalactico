// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaEnemigoBasico.h"
#include "Enemigo.h"
#include "Engine/World.h"

FabricaEnemigoBasico::FabricaEnemigoBasico()
{
}

FabricaEnemigoBasico::~FabricaEnemigoBasico()
{
}
AEnemigo* FabricaEnemigoBasico::CrearEnemigo(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion
) const
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    // Crear enemigo básico
    return Mundo->SpawnActor<AEnemigo>(
        AEnemigo::StaticClass(),
        Posicion,
        Rotacion
    );
}