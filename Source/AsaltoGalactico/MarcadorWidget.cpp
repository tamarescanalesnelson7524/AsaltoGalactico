#include "MarcadorWidget.h"
#include "Components/TextBlock.h"

void UMarcadorWidget::ActualizarPuntuacion(int NuevaPuntuacion)
{
    if (TextoPuntuacion != nullptr)
    {
        TextoPuntuacion->SetText(
            FText::FromString(
                FString::Printf(TEXT("PUNTUACIÓN: %d"), NuevaPuntuacion)
            )
        );
    }
}