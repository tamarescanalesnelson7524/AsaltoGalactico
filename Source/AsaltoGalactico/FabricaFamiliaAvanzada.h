#pragma once

#include "CoreMinimal.h"
#include "FabricaAbstracta.h"

class ASALTOGALACTICO_API FabricaFamiliaAvanzada : public FabricaAbstracta
{
public:

    FabricaFamiliaAvanzada();
    virtual ~FabricaFamiliaAvanzada();

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
