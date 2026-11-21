// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class AEnemigo;
class UWorld;
class ASALTOGALACTICO_API FabricaEnemigos
{
public:
	FabricaEnemigos();
	
	virtual ~FabricaEnemigos();
    // Método Factory Method: crea un enemigo
    virtual AEnemigo* CrearEnemigo(
        UWorld* Mundo,
        const FVector& Posicion,
        const FRotator& Rotacion
    ) const;
};
