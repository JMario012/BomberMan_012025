#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TipoBloque.h"
#include "Bloque.h"
#include "BloqueFactorySimple.generated.h"

UCLASS()
class BOMBERMAN_012025_API UBloqueFactorySimple : public UObject
{
    GENERATED_BODY()

public:
    ABloque* CrearBloque(UWorld* World, ETipoBloque Tipo);

    void RegistrarPrototipo(ETipoBloque Tipo, ABloque* Prototipo);
    const TArray<int32>& ObtenerCodigos() const { return CodigosDeBloques; }

private:
    TMap<ETipoBloque, ABloque*> Prototipos;
    TArray<int32> CodigosDeBloques;
};
