// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaEnemigos.h"
/**
 * 
 */
class ASALTOGALACTICO_API FabricaEnemigoResistente : public FabricaEnemigos
{
public:
	FabricaEnemigoResistente();
	virtual ~FabricaEnemigoResistente();

    virtual AEnemigo* CrearEnemigo(
        UWorld* Mundo,
        const FVector& Posicion,
        const FRotator& Rotacion
    ) const override;
};
