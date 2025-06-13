#pragma once

#include "CoreMinimal.h"
#include "ILaberintoBuilder.h"
#include "LaberintoBuilderSimple.generated.h"

class UBloqueFactorySimple;

UCLASS()
class BOMBERMAN_012025_API ULaberintoBuilderSimple : public UObject, public ILaberintoBuilder
{
    GENERATED_BODY()

public:
    void Inicializar(UWorld* InWorld, UBloqueFactorySimple* InFactory);

    virtual void IniciarConstruccion() override;
    virtual void ConstruirBloque(int32 X, int32 Y, ETipoBloque Tipo) override;
    virtual void FinalizarConstruccion() override;

    const TArray<ABloque*>& ObtenerBloquesConstruidos() const;

private:
    UWorld* Mundo;
    UBloqueFactorySimple* Factory;
    TArray<ABloque*> BloquesConstruidos;
};
