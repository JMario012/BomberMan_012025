#pragma once

#include "CoreMinimal.h"
#include "TipoBloque.h"

class ABloque;

class ILaberintoBuilder
{
public:
    virtual ~ILaberintoBuilder() = default;

    virtual void IniciarConstruccion() = 0;
    virtual void ConstruirBloque(int32 X, int32 Y, ETipoBloque Tipo) = 0;
    virtual void FinalizarConstruccion() = 0;
};
