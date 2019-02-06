#include "Tarefa.h"

Tarefa::Tarefa()
{
    //ctor
}

Tarefa::Tarefa(wxString Prioridade, wxString Data, wxString Descricao)
{
    prioridade = Prioridade;
    data = Data;
    descricao = Descricao;
}



Tarefa::~Tarefa()
{
    //dtor
}
