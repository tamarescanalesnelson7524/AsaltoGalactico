// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class AEnemigo;
class AAsaltoGalacticoProjectile;
class UWorld;
class ASALTOGALACTICO_API FabricaAbstracta
{
public:
	FabricaAbstracta();
	virtual ~FabricaAbstracta();

    virtual AEnemigo* CrearEnemigo(
        UWorld* Mundo,
        const FVector& Posicion,
        const FRotator& Rotacion
    ) const = 0;

    virtual AAsaltoGalacticoProjectile* CrearProyectil(
        UWorld* Mundo,
        const FVector& Posicion,
        const FRotator& Rotacion
    ) const = 0;
};
