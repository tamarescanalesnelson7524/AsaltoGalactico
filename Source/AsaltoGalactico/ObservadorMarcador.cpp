#include "ObservadorMarcador.h"
#include "Engine/Engine.h"

ObservadorMarcador::ObservadorMarcador()
{
    Puntuacion = 0;
}

void ObservadorMarcador::NotificarEnemigoDestruido()
{
    Puntuacion += 100;

    if (GEngine != nullptr)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,
            60.0f,
            FColor::Green,
            FString::Printf(
                TEXT("¡Enemigo destruido! Puntuacion: %d"),
                Puntuacion
            )
        );
    }
}

int ObservadorMarcador::ObtenerPuntuacion() const
{
    return Puntuacion;
}