// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaEnemigos.h"
#include "Enemigo.h"
#include "Engine/World.h"


FabricaEnemigos::FabricaEnemigos()
{
}

FabricaEnemigos::~FabricaEnemigos()
{
}
AEnemigo* FabricaEnemigos::CrearEnemigo(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion
) const
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    // Crear un enemigo básico
    return Mundo->SpawnActor<AEnemigo>(
        AEnemigo::StaticClass(),
        Posicion,
        Rotacion
    );
}