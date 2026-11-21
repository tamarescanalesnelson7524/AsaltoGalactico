// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaFamiliaBasica.h"
#include "Enemigo.h"
#include "AsaltoGalacticoProjectile.h"
#include "Engine/World.h"

FabricaFamiliaBasica::FabricaFamiliaBasica()
{
}

FabricaFamiliaBasica::~FabricaFamiliaBasica()
{
}


AEnemigo* FabricaFamiliaBasica::CrearEnemigo(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion
) const
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    return Mundo->SpawnActor<AEnemigo>(
        AEnemigo::StaticClass(),
        Posicion,
        Rotacion
    );
}

AAsaltoGalacticoProjectile* FabricaFamiliaBasica::CrearProyectil(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion
) const
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    return Mundo->SpawnActor<AAsaltoGalacticoProjectile>(
        AAsaltoGalacticoProjectile::StaticClass(),
        Posicion,
        Rotacion
    );
}