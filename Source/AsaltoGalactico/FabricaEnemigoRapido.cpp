// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaEnemigoRapido.h"
#include "EnemigoRapido.h"
#include "Engine/World.h"


FabricaEnemigoRapido::FabricaEnemigoRapido()
{
}

FabricaEnemigoRapido::~FabricaEnemigoRapido()
{
}

AEnemigo* FabricaEnemigoRapido::CrearEnemigo(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion
) const
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    return Mundo->SpawnActor<AEnemigoRapido>(
        AEnemigoRapido::StaticClass(),
        Posicion,
        Rotacion
    );
}