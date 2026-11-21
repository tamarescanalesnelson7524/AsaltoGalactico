// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaAbstracta.h"
/**
 * 
 */
class ASALTOGALACTICO_API FabricaFamiliaBasica : public FabricaAbstracta
{
public:
	FabricaFamiliaBasica();
	virtual ~FabricaFamiliaBasica();

    virtual AEnemigo* CrearEnemigo(
        UWorld* Mundo,
        const FVector& Posicion,
        const FRotator& Rotacion
    ) const override;

    virtual AAsaltoGalacticoProjectile* CrearProyectil(
        UWorld* Mundo,
        const FVector& Posicion,
        const FRotator& Rotacion
    ) const override;
};
