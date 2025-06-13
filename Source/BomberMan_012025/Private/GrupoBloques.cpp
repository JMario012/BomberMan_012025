#include "GrupoBloques.h"

AGrupoBloques::AGrupoBloques()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AGrupoBloques::AgregarBloque(TScriptInterface<IBloqueComponente> Bloque)
{
    Bloques.Add(Bloque);
}

void AGrupoBloques::Destruir()
{
    for (auto& Bloque : Bloques)
    {
        if (Bloque)
        {
            Bloque->Destruir();
        }
    }

    Destroy(); // Destruye también al grupo actual
}
