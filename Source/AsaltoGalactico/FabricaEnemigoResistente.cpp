// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaEnemigoResistente.h"
#include "EnemigoResistente.h"
#include "Engine/World.h"
FabricaEnemigoResistente::FabricaEnemigoResistente()
{
}

FabricaEnemigoResistente::~FabricaEnemigoResistente()
{
}

AEnemigo* FabricaEnemigoResistente::CrearEnemigo(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion
) const
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    return Mundo->SpawnActor<AEnemigoResistente>(
        AEnemigoResistente::StaticClass(),
        Posicion,
        Rotacion
    );
}