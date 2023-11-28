////////////////////////////////////////////////////////////////////////////////////
//Bibliotecas
////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
////////////////////////////////////////////////////////////////////////////////////
//Estruturas Universais (Utilizado para outras estruturas)
////////////////////////////////////////////////////////////////////////////////////

typedef struct datadaproxinsp{
	int mes;
	int ano;
} DataINSP;

typedef struct cargas{
	char nome_cliente[20];
	char local_origem[15];
	char local_destino[15];
	float custo_carga;
	float distancia;
	int peso;
} CARGAS;

typedef struct camiao{
	char matricula[9];
	float custo_km;
	float carga_maxima;
	DataINSP datadaproxinsp;
	CARGAS cargas;
} CAMIAO;

CAMIAO camiao[100];
int total_camioes = 0;

////////////////////////////////////////////////////////////////////////////////////
//Funções
////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////
//Função para criar um camiao
////////////////////////////////////////////////////////////////////////////////////

void inserirCamiao(CAMIAO camiao[]){
	system("cls");
	int i;
	printf("\tCriacao do camiao n: %d: \n", total_camioes+1);
	
	fflush(stdin);
	printf("\n\tInsira a matricula do camiao (formato XX-XX-XX): ");
	scanf("%s", &camiao[total_camioes].matricula);
	
	fflush(stdin);
	printf("\tInsira a carga maxima do camiao: ");
	scanf("%f", &camiao[total_camioes].carga_maxima);
	
	fflush(stdin);
	printf("\tIndique a proxima inspecao: \n");
	printf("\tIndique o mes e depois o ano: ");
	scanf("%d", &camiao[total_camioes].datadaproxinsp.mes);
	printf("\t");
	scanf("%d", &camiao[total_camioes].datadaproxinsp.ano);
	fflush(stdin);
	printf("\tIndique o custo por km: ");
	scanf("%f", &camiao[total_camioes].custo_km);
	
	total_camioes++;
}

////////////////////////////////////////////////////////////////////////////////////
//Função para exibir informações sobre o camiao
////////////////////////////////////////////////////////////////////////////////////

void mostrarCamiao(CAMIAO camiao[]){
	system("cls");
	
	int i;
	for(i = 0; i < total_camioes; i++){
		printf("\tDados do camiao %d:\n\n", i+1);
		printf("\tMatricula do camiao: %s\n", camiao[i].matricula);
		printf("\tCarga maxima: %.2f\n", camiao[i].carga_maxima);
		printf("\tData da proxima inspecao: %d/%d\n", camiao[i].datadaproxinsp.mes, camiao[i].datadaproxinsp.ano);
		printf("\tCusto por km: %.2f\n\n", camiao[i].custo_km);
		printf("\t________________________\n");
	}
	system ("pause");
}

////////////////////////////////////////////////////////////////////////////////////
//Função para alterar informações do camiao
////////////////////////////////////////////////////////////////////////////////////

void alterarCamiao(CAMIAO camiao[]){
	system("cls");
	int opcao2;
	int numero_camiao;
	
	printf("\n\tInsira o numero do camiao: ");
	scanf("%d", &numero_camiao);
		
	if(numero_camiao <= total_camioes && numero_camiao > 0){
		printf("\n\tQual informação que pretende alterar?\n");
		printf("\t________________________\n");
		printf("\n\t(1) - Matricula");
		printf("\n\t(2) - Carga Maxima");
		printf("\n\t(3) - Data da Proxima Inspecao");
		printf("\n\t(4) - Custo por Km");
		printf("\n\t(5) - Todos os dados");
		printf("\n\t(6) - Nao alterar\n");
		printf("\n\tEscolha a sua opcao: ");
		scanf("%d", &opcao2);
		numero_camiao--;
		switch(opcao2){

        case 1:
			system("cls");
			printf("\n\tIntroduza a matricula: ");
			scanf("%s", &camiao[numero_camiao].matricula);
			
        break;

        case 2:
        	system("cls");
		    printf("\n\tIntroduza a carga maxima: ");
			scanf("%f", &camiao[numero_camiao].carga_maxima);
			
        break;
            
        case 3:
        	system("cls");
		    printf("\n\tIntroduza a data da proxima inspecao:\n");
		    printf("\n\tIntroduza o mes da proxima inspecao: ");
			scanf("%d", &camiao[numero_camiao].datadaproxinsp.mes);
			printf("\n\tIntroduza o ano da proxima inspecao: ");
			scanf("%d", &camiao[numero_camiao].datadaproxinsp.ano);
			
        break;   
		
		case 4:
			system("cls");
			printf("\n\tIntroduza o custo por km: ");
			scanf("%f", &camiao[numero_camiao].custo_km);
			
		break; 
		
		case 5:
			system("cls");
			printf("\n\tIntroduza todos os novos dados: ");
			
			printf("\n\n\tIntroduza a matricula: ");
			scanf("%s", &camiao[numero_camiao].matricula);
			
			printf("\tIntroduza a carga maxima: ");
			scanf("%f", &camiao[numero_camiao].carga_maxima);
			
			printf("\tIntroduza a data da próxima inspecao:\n");
		    printf("\tIntroduza o mes da próxima inspecao: ");
			scanf("%d", &camiao[numero_camiao].datadaproxinsp.mes);
			printf("\tIntroduza o ano da próxima inspecao: ");
			scanf("%d", &camiao[numero_camiao].datadaproxinsp.ano);

			printf("\tIntroduza o custo por km: ");
			scanf("%f", &camiao[numero_camiao].custo_km);
		
		break;
		
		case 6:
        	return;
        break;   
        }
	}else{
		printf("\n\tERRO! Nao existe!!\n\n");
		system ("pause");
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Função para inserir nova carga e atribui-la a um camiao
////////////////////////////////////////////////////////////////////////////////////

void registarCargas(CARGAS cargas_camiao[]){
	system("cls");
	int numero_camiao;

	printf("\n\tInsira o numero do camiao que pretende associar a carga: ");
	scanf("%d", &numero_camiao);
	printf("\t________________________\n");
	if(numero_camiao <= total_camioes && numero_camiao > 0){
		numero_camiao--;
		fflush(stdin);
		printf("\n\tIntroduza o nome do cliente: ");
		scanf("%s", &cargas_camiao[numero_camiao].nome_cliente);	
	
		fflush(stdin);
		printf("\tIntroduza o local de origem: ");
		scanf("%s", &cargas_camiao[numero_camiao].local_origem);
		
		fflush(stdin);
		printf("\tIntroduza o local de destino: ");
		scanf("%s", &cargas_camiao[numero_camiao].local_destino);
		
		fflush(stdin);
		printf("\tIntroduza a distancia (Em km): ");
		scanf("%f", &cargas_camiao[numero_camiao].distancia);
		
		do {
			
  		fflush(stdin);
		printf("\tIntroduza o peso (Em kg): ");
		scanf("%d", &cargas_camiao[numero_camiao].peso);
		}while(cargas_camiao[numero_camiao].peso < camiao[numero_camiao].carga_maxima);
	
	
	}
	else{
		printf("\n\tNao existe camiao com esse numero!\n\n");
		system ("pause");
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Função para eliminar um camiao já existente
////////////////////////////////////////////////////////////////////////////////////

void eliminarcamiao(CAMIAO camiao[]){
	system("cls");
	
	int numero_camiao,pos;
	printf("\tQual camiao pretende eliminar?\n");
	scanf("%d", &pos);
	pos--;
	for(numero_camiao = pos; numero_camiao < total_camioes; numero_camiao++){
		camiao[numero_camiao] = camiao[numero_camiao+1];
	}
	pos=pos+1;
	printf("\tCamiao numero %d eliminado\n", pos);
	system ("pause");
	
	
}


////////////////////////////////////////////////////////////////////////////////////
//Função para mostrar as informacoes das cargas dos camioes
////////////////////////////////////////////////////////////////////////////////////

void listarCargasCamiao(CARGAS cargas_camiao[]){
	
	system("cls");
	int i;
	int w;
	float valorkm;

	
	for(i = 0; i < total_camioes; i++){
		printf("\t________________________\n");
		printf("\n\t\tCargas do camiao %d:\n\n", i+1);
		printf("\tNome do cliente: %s\n", cargas_camiao[i].nome_cliente);
		printf("\tLocal de origem: %s\n", cargas_camiao[i].local_origem);
		printf("\tLocal de destino: %s\n", cargas_camiao[i].local_destino);
		printf("\tDistancia: %.2f\n", cargas_camiao[i].distancia);
		printf("\tPeso: %d\n\n", cargas_camiao[i].peso);
		w=0;
		do {
  		w=w+1000;			
		}while(cargas_camiao[i].peso>w);
		valorkm = cargas_camiao[i].distancia + 50*(w/1000);
		printf("\tPreco total: %.2f\n\n", valorkm);
	}
	system ("pause");
}

////////////////////////////////////////////////////////////////////////////////////
//Função para o submenu de Registar um novo camiao
////////////////////////////////////////////////////////////////////////////////////
		
void menucriar(){
	int opcao;
	do{	
		system("cls");	
		printf("\t________________________\n");
		printf("\t Menu registo camioes \n\n");
		printf("\t(1) - Inserir informacao\n");
		printf("\t(2) - Mostrar informacao\n");
		printf("\t(3) - Alterar informacao\n");
		printf("\t(4) - Eliminar informacao\n");
		printf("\t(5) - Voltar\n");
		printf("\t________________________\n");
		printf("\tEscolha a sua opcao: ");
        fflush(stdin);
		scanf("%d", &opcao);
        switch(opcao){

        case 1:
		    inserirCamiao(camiao);
        break;

        case 2:
            mostrarCamiao(camiao);
        break;
            
        case 3:
        	alterarCamiao(camiao);
        break;  
		
		case 4:
        	eliminarcamiao(camiao);
        break;   
                
		case 5:
			return;
        break;  
        }
        
    } while (opcao != 5);
}

////////////////////////////////////////////////////////////////////////////////////
//Função para mostrar informacoes do camiao
////////////////////////////////////////////////////////////////////////////////////

void menumostrar(){
	int opcao;
    		mostrarCamiao(camiao);
        }
        
////////////////////////////////////////////////////////////////////////////////////
//Função para colocar o programa em fullscreen
////////////////////////////////////////////////////////////////////////////////////        
     
void fullscreen(){
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
	    
////////////////////////////////////////////////////////////////////////////////////
//Função principal para inicializar o programa
////////////////////////////////////////////////////////////////////////////////////        
        
int main(){
	fullscreen();
    setlocale(LC_ALL, "Camiao");
	int opcao;

	do{	
		system("cls");
		printf("\t________________________\n");
		printf("\tMENU PRINCIPAL\n\n");
		printf("\t(1) - Registo de camioes \n");
		printf("\t(2) - Listagem de camioes \n");
		printf("\t(3) - Registo de cargas \n");
        printf("\t(4) - Listagem de cargas \n");
		printf("\t(5) - Sair \n");
		printf("\t________________________\n");
		printf("\tEscolha a sua opcao: ");
        fflush(stdin);
		scanf("%d", &opcao);

        switch (opcao){

        case 1:
			menucriar();
        break;
		
		case 2:
            menumostrar();
        break;
            
        case 3:
			registarCargas(camiao);
        break;  
        
		case 4:
			listarCargasCamiao(camiao);
        break;
        
		case 5:
			return 0;
        break;  
        }
        
    }while (opcao != 5);
}
