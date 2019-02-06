#include <wx/string.h>

#ifndef TAREFA_H
#define TAREFA_H


class Tarefa
{
    public:
        Tarefa();
        Tarefa(wxString Prioridade, wxString Data, wxString Descricao);
        virtual ~Tarefa();

        wxString Getprioridade() { return prioridade; }
        void Setprioridade(wxString val) { prioridade = val; }
        wxString Getdata() { return data; }
        void Setdata(wxString val) { data = val; }
        wxString Getdescricao() { return descricao; }
        void Setdescricao(wxString val) { descricao = val; }

    protected:

    private:
        wxString prioridade;
        wxString data;
        wxString descricao;
};

#endif // TAREFA_H
