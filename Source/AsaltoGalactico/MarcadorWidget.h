#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MarcadorWidget.generated.h"

UCLASS()
class ASALTOGALACTICO_API UMarcadorWidget : public UUserWidget
{
    GENERATED_BODY()

public:

    // Texto que mostrara la puntuacion
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* TextoPuntuacion;

    // Actualizar la puntuacion en pantalla
    UFUNCTION(BlueprintCallable, Category = "Marcador")
    void ActualizarPuntuacion(int NuevaPuntuacion);
};