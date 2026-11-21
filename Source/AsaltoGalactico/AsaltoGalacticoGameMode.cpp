// Copyright Epic Games, Inc. All Rights Reserved.

#include "AsaltoGalacticoGameMode.h"
#include "AsaltoGalacticoPawn.h"
#include "FondoEspacial.h"
#include "FabricaEnemigoResistente.h"
#include "FabricaEnemigoBasico.h"
#include "FabricaEnemigoRapido.h"

#include "FabricaFamiliaBasica.h"
#include "FabricaFamiliaAvanzada.h"

#include "FachadaJuego.h"
#include "ObservadorMarcador.h"
#include "ConstructorEnemigo.h"
#include "Enemigo.h"
#include "TimerManager.h"
#include "AsaltoGalacticoProjectile.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/ProjectileMovementComponent.h"

AAsaltoGalacticoGameMode::AAsaltoGalacticoGameMode()
{
	// Establecer la clase del jugador
	DefaultPawnClass = AAsaltoGalacticoPawn::StaticClass();
}

void AAsaltoGalacticoGameMode::BeginPlay()
{
    Super::BeginPlay();

    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        FVector PosicionFondo(30.0f, 80.0f, 165.0f);
        FRotator RotacionFondo = FRotator::ZeroRotator;

        Mundo->SpawnActor<AFondoEspacial>(
            AFondoEspacial::StaticClass(),
            PosicionFondo,
            RotacionFondo
        );
    }
    CrearMultiplesEnemigos();

    // Configurar el temporizador para generar nuevas oleadas
    GetWorldTimerManager().SetTimer(
        TimerOleadas,this,
        &AAsaltoGalacticoGameMode::GenerarNuevaOleada,
        IntervaloOleadas,true
    );
}


void AAsaltoGalacticoGameMode::CrearMultiplesEnemigos()
{
    UWorld* Mundo = GetWorld();

    if (Mundo == nullptr)
    {
        return;
    }

    FRotator Rotacion = FRotator::ZeroRotator;

    // 1. CREAR 3 ENEMIGOS BÁSICOS
   FabricaEnemigoBasico FabricaBasico;
    for (int32 i = 0; i < 3; i++)
    {
        FVector Posicion(-390.0f, -1000.0f + (i * 300.0f), 214.7279f);
        AEnemigo* Enemigo = FabricaBasico.CrearEnemigo(Mundo, Posicion, Rotacion);
        if (Enemigo != nullptr)
        {
            Enemigo->ConfigurarVelocidad(150.0f);
            Enemigo->AgregarObservador(&ObservadorMarcadorJuego);
        }
    }

    // 2. CREAR 3 ENEMIGOS RÁPIDOS
    FabricaEnemigoRapido FabricaRapido;

    for (int32 i = 0; i < 3; i++)
    {
        FVector Posicion(-390.0f, 0.0f + (i * 300.0f), 214.7279f);
        AEnemigo* Enemigo = FabricaRapido.CrearEnemigo(Mundo, Posicion, Rotacion);
        if (Enemigo != nullptr)
        {
            Enemigo->AgregarObservador(&ObservadorMarcadorJuego);
        }
    }

    // 3. CREAR 3 ENEMIGOS RESISTENTES
    FabricaEnemigoResistente FabricaResistente;
    for (int32 i = 0; i < 3; i++)
    {
        FVector Posicion(-390.0f, 1000.0f + (i * 300.0f), 214.7279f);
AEnemigo* Enemigo = FabricaResistente.CrearEnemigo(Mundo, Posicion, Rotacion);

        if (Enemigo != nullptr)
        {
            Enemigo->AgregarObservador(&ObservadorMarcadorJuego);
        }
    }

    //Metododo del Patron Abstrack Factory
    /*
    FabricaFamiliaAvanzada FabricaAvanzada;
    for (int32 i = 0; i < 3; i++)
    {
        FVector Posicion(-390.0f, -1000.0f + (i * 300.0f), 214.7279f);
        AEnemigo* Enemigo = FabricaAvanzada.CrearEnemigo(Mundo, Posicion, Rotacion);
        if (Enemigo != nullptr)
        {
            Enemigo->AgregarObservador(&ObservadorMarcadorJuego);
        }
    }

    // 2. CREAR 3 ENEMIGOS RÁPIDOS
    FabricaFamiliaBasica FabricaBasica;

    for (int32 i = 0; i < 3; i++)
    {
        FVector Posicion(-390.0f, 0.0f + (i * 300.0f), 214.7279f);
        AEnemigo* Enemigo = FabricaBasica.CrearEnemigo(Mundo, Posicion, Rotacion);
        if (Enemigo != nullptr)
        {
            Enemigo->ConfigurarVelocidad(150.0f);
            Enemigo->AgregarObservador(&ObservadorMarcadorJuego);
        }
    }*/

   /* //Patron builder
    // 2. CREAR 3 ENEMIGOS UTILIZANDO BUILDER

    ConstructorEnemigo Constructor;

    for (int32 i = 0; i < 8; i++)
    {
        FVector Posicion(-390.0f, -100.0f + (i * 300.0f), 214.7279f);

        AEnemigo* Enemigo = Constructor
            .ConfigurarVida(200.0f)
            .ConfigurarVelocidad(250.0f)
            .Construir(Mundo, Posicion, Rotacion);

        if (Enemigo != nullptr)
        {
            Enemigo->AgregarObservador(&ObservadorMarcadorJuego);
        }
    }*/

    // Patron facade
    /*// 3. CREAR ENEMIGOS UTILIZANDO FACADE

    FachadaJuego Fachada;

    // Crear 3 enemigos básicos
    for (int32 i = 0; i < 3; i++)
    {
        FVector Posicion(-390.0f, 800.0f + (i * 300.0f), 214.7279f);

        AEnemigo* Enemigo = Fachada.CrearEnemigoBasico(
            Mundo,
            Posicion,
            Rotacion
        );

        if (Enemigo != nullptr)
        {
            Enemigo->AgregarObservador(&ObservadorMarcadorJuego);
        }
    }

    // Crear 3 enemigos resistentes
    for (int32 i = 0; i < 3; i++)
    {
        FVector Posicion(-390.0f, 1800.0f + (i * 300.0f), 214.7279f);

        AEnemigo* Enemigo = Fachada.CrearEnemigoResistente(
            Mundo,
            Posicion,
            Rotacion
        );

        if (Enemigo != nullptr)
        {
            Enemigo->AgregarObservador(&ObservadorMarcadorJuego);
        }
    }

    // Crear 3 enemigos personalizados
    for (int32 i = 0; i < 3; i++)
    {
        FVector Posicion(-390.0f, 2800.0f + (i * 300.0f), 214.7279f);

        AEnemigo* Enemigo = Fachada.CrearEnemigoPersonalizado(
            Mundo,
            Posicion,
            Rotacion,
            300.0f,
            200.0f
        );

        if (Enemigo != nullptr)
        {
            Enemigo->AgregarObservador(&ObservadorMarcadorJuego);
        }
    }*/

}

void AAsaltoGalacticoGameMode::GenerarNuevaOleada()
{
    UE_LOG(LogTemp, Warning, TEXT("¡NUEVA OLEADA DE ENEMIGOS!"));

    CrearMultiplesEnemigos();
}