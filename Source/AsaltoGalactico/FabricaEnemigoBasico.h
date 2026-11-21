// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaEnemigos.h"
/**
 * 
 */
class ASALTOGALACTICO_API FabricaEnemigoBasico : public FabricaEnemigos
{
public:
	FabricaEnemigoBasico();
	virtual ~FabricaEnemigoBasico();

    // Redefinir el método de creación
    virtual AEnemigo* CrearEnemigo(
        UWorld* Mundo,
        const FVector& Posicion,
        const FRotator& Rotacion
    ) const override;
};
