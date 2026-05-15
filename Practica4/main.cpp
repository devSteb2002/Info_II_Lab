#include "red.h"
#include <limits>
using namespace std;

void showOptions();

int main()
{

    cout << "---------------------------------------------------" << endl;
    cout << "                    MI RED                         " << endl;
    cout << "---------------------------------------------------" << endl;


    Red* red = new Red();

    string option;
    int value;
    bool IsInOption = false;


    //opcion 1
    bool isRouterCreated = false;
    string nameRouter;


    do {

        if (!IsInOption){
            bool   isInMenu = false;

            showOptions();

            cout << "Selecciona una opcion: ";
            getline(cin, option);

            for (char item: option){
                if (!isdigit(static_cast<unsigned char>(item))){
                    cout << endl;
                    cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                    cout << endl;
                    isInMenu = true;
                    break;
                }
            }

            if (isInMenu) continue;

            if (option.empty()){
                cout << endl;
                cout << "Entrada vacia, ingrese algo." << endl;
                cout << endl;
            }

            value = stoi(option);
            if (value < 1 || value > 6){
                cout << endl;
                cout << "Solo hay 5 opciones, vuelva a intentar." << endl;
                cout << endl;
                continue;
            }

            IsInOption = true;
        }
        else {
            //---------------------------------------------------------------------------------------//
            //                      OPCION # 1
            //---------------------------------------------------------------------------------------//
            if (value == 1){
                if (!isRouterCreated){
                    cout << endl;
                    cout << "-----------------------------------------------------" << endl;
                    cout << "             CREACION DE ROUTER                " << endl;
                    cout << "-----------------------------------------------------" << endl;

                    cout << "Digite el nombre del router: ";
                    getline(cin, nameRouter);

                    if (red->alreadyExistRouter(nameRouter)){
                        cout << "El nombre " << nameRouter << " ya existe, vuelva a intentar." << endl;
                        continue;
                    }

                    red->addNewRouter(nameRouter);
                    isRouterCreated = true;
                }
                else {
                    cout << "--------------------------------------------" << endl;
                    cout << " Creacion router: opciones " << endl;
                    cout << "--------------------------------------------" << endl;

                    string option_1;

                    do {
                        cout << "1.) Crear enlaces" << endl;
                        cout << "2.) Salir" << endl;
                        cout << "Ingrese una opcion: ";
                        getline(cin, option_1);

                        bool validNumber = true;

                        for (char c : option_1){
                            if (!isdigit(static_cast<unsigned char>(c))){
                                cout << "Ingrese un numero, vuelva a intentar." << endl;
                                validNumber = false;
                                break;
                            }
                        }

                        if (!validNumber) continue;
                        int val = stoi(option_1);
                        if (val < 1 || val > 2){
                            cout << "Valor fuera de rango, vuelva a intentar." << endl;
                            continue;
                        }

                        break;
                    } while (true);

                    if (option_1 == "1"){
                        cout << "-------------------------------------" << endl;
                        cout << "  Mostrando routers             " << endl;
                        cout << "-------------------------------------" << endl;
                        red->showRoutters();

                        string nameRouterSelected;
                        string  cost;
                        bool   enterRouter = false;
                        do {

                            if (!enterRouter){
                                cout << "Ingrese el router a generar enlace: ";
                                getline(cin, nameRouterSelected);

                                if (!red->alreadyExistRouter(nameRouterSelected)){
                                    cout << "Router no encontrado, vuelva a intentar." << endl;
                                    continue;
                                }

                                enterRouter = true;
                            }else{
                                cout << "Ingrese el costo: ";
                                getline(cin, cost);

                                bool isNumber = true;
                                for (char c : cost){
                                    if (!isdigit(static_cast<unsigned char>(c))){
                                        cout << "Solo se permite numeros, vuelva a intentar." << endl;
                                        isNumber = false;
                                        break;
                                    }
                                }

                                if (!isNumber) continue;

                                if (stoi(cost) < 0){
                                    cout << "Solo se permiten numeros positivos, vuelva a intentar." << endl;
                                    continue;
                                }

                                break;
                            }

                        } while (true);
                        red->addLinks(nameRouter, nameRouterSelected, static_cast<unsigned short>(stoi(cost)));

                        cout << "--------------------------------------------------" << endl;
                        cout << "Router creado exitosamente." << endl;
                        cout << "--------------------------------------------------" << endl;
                    }
                    else if (option_1 == "2"){
                        isRouterCreated = false;
                        IsInOption = false;
                    }
                }
            }
            //---------------------------------------------------------------------------------------//
            //                                    OPCION # 2
            //---------------------------------------------------------------------------------------//
            else if (value == 2){

                cout << "----------------------------------------------" << endl;
                cout << "    ACTUALIZACION ROUTER"              << endl;
                cout << "----------------------------------------------" << endl;
                cout << "-------------------------------------" << endl;
                cout << "  Mostrando routers             " << endl;
                cout << "-------------------------------------" << endl;
                red->showRoutters();

                string selecteRouter;
                string selectedRouter2;
                string valueLink;
                bool   firstRouter = true;
                bool   secondRouter = false;
                do {
                    if (firstRouter){
                        cout << "Ingrese el router: ";

                        getline(cin, selecteRouter);

                        if (!red->alreadyExistRouter(selecteRouter)){
                            cout << "Router no encontrado, vuelva a intentar." << endl;
                            continue;
                        }

                        firstRouter = false;
                        secondRouter = true;
                    }

                   if (secondRouter){
                        cout << "Ingrese el router del enlace: ";
                        getline(cin, selectedRouter2);

                        if (!red->alreadyExistRouter(selectedRouter2)){
                            cout << "Router no encontrado, vuelva a intentar." << endl;
                            continue;
                        }

                        if (selecteRouter == selectedRouter2){
                            cout << "Los routers deben ser diferentes, vuelva a intentar." << endl;
                            continue;
                        }

                        secondRouter = false;
                    }


                   cout << "Ingese el valor del enlace: ";
                    getline(cin, valueLink);
                   bool validNumber = true;

                   for (char c : valueLink){
                       if (!isdigit(static_cast<unsigned char>(c))){
                           cout << "Solo se permite numeros, vuelva a intentar." << endl;
                           validNumber = false;
                           break;
                       }
                   }

                   if (!validNumber) continue;

                   break;
                } while (true);

                red->updateRouter(selecteRouter, selectedRouter2, static_cast<unsigned short>(stoi(valueLink)));
                 IsInOption = false;

                cout << "--------------------------------------------------" << endl;
                cout << "Router actualizado exitosamente" << endl;
                cout << "--------------------------------------------------" << endl;
            }
            //---------------------------------------------------------------------------------------//
            //                                    OPCION # 3
            //---------------------------------------------------------------------------------------//
            else if (value == 3){
                cout << "----------------------------------------------" << endl;
                cout << "    ELIMINACION ROUTER"              << endl;
                cout << "----------------------------------------------" << endl;
                cout << "-------------------------------------" << endl;
                cout << "  Mostrando routers             " << endl;
                cout << "-------------------------------------" << endl;
                 red->showRoutters();

                string routerToDelete;
                do {
                    cout << "Ingrese el router a eliminar: ";
                    getline(cin, routerToDelete);

                    if (!red->alreadyExistRouter(routerToDelete)){
                        cout << "Router no encontrado, vuelva a intentar." << endl;
                        continue;
                    }

                    break;
                } while(true);

                red->deleteRouter(routerToDelete);

                cout << "--------------------------------------------------" << endl;
                cout << "Router eliminado exitosamente" << endl;
                cout << "--------------------------------------------------" << endl;

                IsInOption = false;
            }
            //---------------------------------------------------------------------------------------//
            //                                    OPCION # 4
            //---------------------------------------------------------------------------------------//
            else if (value == 4){
                cout << "----------------------------------------------" << endl;
                cout << "   MOSTRAR ROUTER"              << endl;
                cout << "----------------------------------------------" << endl;

                string routerToShow;

                do {
                    cout << "Ingrese el nombre del router: ";
                    getline(cin, routerToShow);

                    if (!red->alreadyExistRouter(routerToShow)){
                        cout << "Router no encontrado, vuelva a intentar." << endl;
                        continue;
                    }

                    break;
                } while (true);

                red->showRouterByName(routerToShow);
                IsInOption = false;

                cout << endl;
            }
            //---------------------------------------------------------------------------------------//
            //                                    OPCION # 5
            //---------------------------------------------------------------------------------------//
            else if (value == 5){
                cout << "----------------------------------------------" << endl;
                cout << "          CAMINOS "              << endl;
                cout << "----------------------------------------------" << endl;


                string selectedRouterOrigin;
                string selectedRouterDestiny;
                bool   isSelectedFirst = false;

                do {
                    if (!isSelectedFirst){
                        cout << "Ingrese el router de origin: ";
                        getline(cin ,selectedRouterOrigin);

                        if (!red->alreadyExistRouter(selectedRouterOrigin)){
                            cout << "Router no encontrado, vuelva a intentar." << endl;
                            continue;
                        }

                        isSelectedFirst = true;
                    }

                    cout << "Ingrese el router de destino: ";
                    getline(cin, selectedRouterDestiny);

                    if (!red->alreadyExistRouter(selectedRouterDestiny)){
                        cout << "Router no encontrado, vuelva a intentar." << endl;
                        continue;
                    }

                    break;
                } while (true);

                red->calculateShortWay(selectedRouterOrigin, selectedRouterDestiny);
                IsInOption = false;
            }
            else {
                break;
            }
        }
    } while(true);


    delete red;

    return 0;
}


void showOptions(){
    cout << "1.) Crear router. " << endl;
    cout << "2.) Actualizar router" << endl;
    cout << "3.) Eliminar router." << endl;
    cout << "4.) Mostrar router" << endl;
    cout << "5.) Mostrar caminos cortos del router." << endl;
    cout << "6.) Salir." << endl;
}
