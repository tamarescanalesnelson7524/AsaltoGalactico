// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ObservadorMarcador.h"
//#include "MarcadorWidget.h"
#include "AsaltoGalacticoGameMode.generated.h"

UCLASS()
class ASALTOGALACTICO_API AAsaltoGalacticoGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AAsaltoGalacticoGameMode();

protected:
    virtual void BeginPlay() override;

   
    void CrearMultiplesEnemigos();
    void GenerarNuevaOleada();
  



private:
    // Observador que recibira la notificacion
    ObservadorMarcador ObservadorMarcadorJuego;
   

    // Temporizador para controlar las oleadas
    FTimerHandle TimerOleadas;

    // Tiempo entre cada oleada
    float IntervaloOleadas = 15.0f;
};


