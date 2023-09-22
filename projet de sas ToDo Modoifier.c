#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//struct
      typedef struct{
        	int jours,annne,moins;
		}deadline;
        typedef struct{
        	int identifiant;
        	char titre[50];
        	char description[100];
            deadline line;
        	char status[50];
		 }tache;
 //variable global     
int i,j,k=0;
tache T[100];
tache tri;




//Ajouter une nouvelle tâche 
void ajouterSeul(){
	   
	       printf("ajouter un seul tache :\n ");
	
			T[k].identifiant=k+1;
			printf("identifiant : %d \n",T[k].identifiant);
		    printf("donner un titre : ");
	        scanf(" %[^\n]", T[k].titre);  
	        printf("donner un description : ");
	        scanf(" %[^\n]", T[k].description);  
		    printf("donner un deadline : ");
		    
					do {
				    printf("Jour : ");
				    scanf("%d", &T[k].line.jours);
				
				    printf("Mois : ");
				    scanf("%d", &T[k].line.moins);
				
				    printf("Annee : ");
				    scanf("%d", &T[k].line.annne);
				
				    if (T[k].line.annne < 0 || T[k].line.moins < 1 || T[k].line.moins > 12 || T[k].line.jours < 1) {
				        printf("Date invalide. Veuillez entrer une date valide.\n");
				    }
				   } while(T[k].line.annne < 0 || T[k].line.moins < 1 || T[k].line.moins > 12 || T[k].line.jours < 1);

		    printf(" les status : finalise ,encours, realiser \n");
		    printf("donner un stauts : ");
		    scanf("%s",&T[k].status);
		    k++;	    
		
	}
	void affiche(){ 	
	printf("******************                     les donnne  de tache To DO                           *********************** \n");
		    printf("     Identifiant      |        Titre         |     Description          |   Deadline         |  Status          |\n");
			for(i=0;i<k;i++){
		
		
		    printf("        %d             |        %s           |    %s                 |   %d / %d / %d    |   %s       |\n",T[i].identifiant,T[i].titre,T[i].description,T[i].line.jours,T[i].line.moins,T[i].line.annne ,T[i].status);

//     	   	printf("                               Identifiant :    %d\n"                             ,T[i].identifiant);
//     	   	printf("                               Titre :          %s \n"                            ,T[i].titre);
//     	   	printf("                               Description :    %s\n"                             ,T[i].description);
//     	   	printf("                               Deadline :       %d / %d / %d\n"                   ,T[i].line.jours,T[i].line.moins,T[i].line.annne);
//     	   	printf("                               Status :         %s\n"                             ,T[i].status);	
     	   	
		 }
	}
//Ajouter plusieurs nouvelles tâches.
  void ajouterPlusierus(){
  	int nbrtache; // Declare n
    int i; // Declare i
	   printf("ajouter un plusieurs tache : \n");
		printf("donner un nombre de taches :");
		scanf("%d",&nbrtache);
		nbrtache+=k;
		for(i=k;i<nbrtache;i++){
			T[i].identifiant=i+1;
			printf("identifiant : %d \n",T[i].identifiant);
		    printf("donner un titre : ");
	        scanf(" %[^\n]", T[i].titre);  
	        printf("donner un description : ");
	        //		    99 specifies the maximum number of characters to read    ^\n pour espace
	        scanf(" %[^\n]", T[i].description);
		    printf("donner un deadline : ");
		    printf("jours : ");
		    scanf("%d",&T[i].line.jours);
		    printf("mois : ");
		    scanf("%d",&T[i].line.moins);
		    printf("annee : ");
		    scanf("%d",&T[i].line.annne);
		    printf(" les status : finalise ,encours, realiser \n");
		    printf("donner un stauts : ");
		    scanf("%s",T[i].status);
		  
			k++; 
		}
		}
		//Menu Ajouter 
void MenuAjourt(){
	               int choix;
					    printf(" ------------------------------------------- Menu Ajouter -----------------------------------------\n");
					    printf(" * Choisir une option :                                                                           *\n");
					    printf(" * 1 - Ajouter un seul tache                                                                      *\n");
					    printf(" * 2 - Ajouter Plusieurs tache :                                                                  *\n");
					    printf(" * 0 - Retour                                                                                     *\n");
					    printf(" --------------------------------------------------------------------------------------------------\n");
                printf("donner un choix Ajouter :=>  ");
                scanf("%d",&choix);
				
				switch(choix){
                	case 1: ajouterSeul();
					        system("cls");
					         affiche();
					         MenuAjourt();
					        break;
                	case 2: ajouterPlusierus();
					        system("cls");
					         affiche();
					         MenuAjourt();
					        break;
                	case 0: system("cls");
					       return ;
                	      
					        break;
				}
	
}
			//Afficher la liste de toutes les tâches 
			//tri alphabitique
void triAlph(){
	    printf("------Trier les tâches par ordre alphabétique------\n");
	    for(i=0;i<k;i++){
	    	for(j=i+1;j<k;j++){
	    		if(strcmp(T[i].titre,T[j].titre)>0){
	    			tri=T[i];
	    			T[i]=T[j];
	    			T[j]=tri;
				}
			}
		}
}
//Trier les tâches par deadline.
void trideadline(){
	   
    printf("------Trier les tâches par ordre deadline------\n");
    int i, j;
   

    for(i = 0; i < k; i++) {
        for(j = i + 1; j < k; j++) {
            if(T[i].line.annne > T[j].line.annne) {
                tri = T[i];
                T[i] = T[j];
                T[j] = tri;
            }
            else if(T[i].line.annne == T[j].line.annne && T[i].line.moins > T[j].line.moins) {
                tri = T[i];
                T[i] = T[j];
                T[j] = tri;
            }
            else if(T[i].line.annne == T[j].line.annne && T[i].line.moins == T[j].line.moins && T[i].line.jours > T[j].line.jours) {
                tri = T[i];
                T[i] = T[j];
                T[j] = tri;
            }
        }
    
}

     }
	//function a moins 3jours
void affdidlin(){
	    printf(" ---------------------------------------------------------------------------------------\n");
	    printf("-                                                                                      -\n");
		printf("-                               les donnne  de tache To DO                             -\n");
		printf("-                                    au moins      3 jours                             -\n");
		printf("-                                                                                      -\n");
		printf("----------------------------------------------------------------------------------------\n");
	 //typedef struct predefinie  /  function time ()
	   time_t t=time(NULL);
                     // struct sur time.h 
                     struct tm dt=*localtime(&t);
                     int j=dt.tm_mday;
                     int m=dt.tm_mon+1;
                     int a=dt.tm_year+1900;
                     for(i=0;i<k;i++){
                    int jours = ((T[i].line.annne-a) * 365 +
					           (T[i].line.moins-m) * 30 + 
					                (T[i].line.jours-j ));
					    if(jours>0&&jours<=3){
					    		
           printf("     Identifiant      |        Titre         |     Description              |   Deadline         |  Status          |\n");
		   printf("        %d            |        %s           |        %s               |   %d / %d / %d    |   %s        |\n",T[i].identifiant,T[i].titre,T[i].description,T[i].line.jours,T[i].line.moins,T[i].line.annne ,T[i].status);

//     	   	printf("                               Identifiant :    %d\n"                             ,T[i].identifiant);
//     	   	printf("                               Titre :          %s \n"                            ,T[i].titre);
//     	   	printf("                               Description :    %s\n"                             ,T[i].description);
//     	   	printf("                               Deadline :       %d / %d / %d\n"                   ,T[i].line.jours,T[i].line.moins,T[i].line.annne);
//     	   	printf("                               Status :         %s\n"                             ,T[i].status);	
					    	
						}
					 }
     	   	
		 }

//function Menu trier 
void operationTri() {
	        
					    int choix;
					    printf(" ------------------------------------------- Menu TRIER -------------------------------------------\n");
					    printf(" * Choisir une option :                                                                           *\n");
					    printf(" * 1 - Trier les tâches par ordre alphabétique                                                    *\n");
					    printf(" * 2 - Trier les tâches par deadline                                                              *\n");
					    printf(" * 3 - Afficher les tâches dont la deadline est dans 3 jours ou moins                             *\n");
					    printf(" * 0 - Retour                                                                                     *\n");
					    printf(" --------------------------------------------------------------------------------------------------\n");

						    printf("Donner votre choix : ");
						    scanf("%d", &choix);

						    switch (choix) {
						        case 1:
						        	system("cls");
						            triAlph();
						            affiche();
						            operationTri();
						            break;
						        case 2:
						        	system("cls");
						             trideadline();
						             affiche();
						             operationTri();
						            break;
						        case 3:
						        	system("cls");
						             affdidlin();
						             operationTri();
						            break;
						        case 0:
						        	system("cls");
						        	system("cls");
							        
						        default:
						            printf("Choix invalide. Veuillez réessayer.\n"); break;
						            
						    }
						    
}

//Modifier une tâche:
void Modifier(){
	
		    printf(" ------------------------------------------- Menu Modifier  --------------------------------------------\n");
            printf(" *                                         Modifier les Tâches :                                       *\n");
            printf(" *                                       1-Modifier la description d'une tâche.                        *\n");
            printf(" *                                       2-Modifier le statut d’une tâche                              *\n");
            printf(" *                                       3-Modifier le deadline d’une tâche                            *\n");
			printf(" *                                       0-return                                                      *\n");
			printf(" *-----------------------------------------------------------------------------------------------------*\n");
   
				     int c, id;
    affiche(); 

    printf("donner un choix : ");
    scanf("%d", &c);

    switch (c) {
        case 1:
            printf("donner un identifiant a modifier : ");
            scanf("%d", &id);
            for ( i = 0; i < k; i++) {
                if (T[i].identifiant == id) {
                    printf("donner une nouvelle description : ");
                    scanf(" %[^\n]",T[i].description); 
                    printf("description modifié.\n");
                }
               
            } 
          
            break;

        case 2:
            printf("donner un identifiant a modifier : ");
            scanf("%d", &id);
            for ( i = 0; i < k; i++) {
                if (T[i].identifiant == id) {
                    printf("donner un nouveau statut : ");
                    scanf("%s",T[i].status);
                    printf("statut modifié.\n");
                }
               
            }
            
            break;

        case 3:
            printf("donner un identifiant a modifier : ");
            scanf("%d", &id);
            for ( i = 0; i < k; i++) {
                if (T[i].identifiant == id) {
                    printf("nouveau deadline : \n");
                    do {
				    printf("Jour : ");
				    scanf("%d", &T[i].line.jours);
				
				    printf("Mois : ");
				    scanf("%d", &T[i].line.moins);
				
				    printf("Annee : ");
				    scanf("%d", &T[i].line.annne);
				
				    if (T[i].line.annne < 0 || T[i].line.moins < 1 || T[i].line.moins > 12 || T[i].line.jours < 1) {
				        printf("Date invalide. Veuillez entrer une date valide.\n");
				    }
				    } while(T[i].line.annne < 0 || T[i].line.moins < 1 || T[i].line.moins > 12 || T[i].line.jours < 1);
                    printf("deadline modifié.\n");
                }
               
            }
            
            break;

        case 0:
          	system("cls");
             return ;

            break;

        default:
            printf("Aucune tâche  n'a été trouvée (on a 1 - 2 - 3 - 0)\n"); break;
    }
    Modifier();
}


//Supprimer une tâche par identifiant.
void supprimer(){
	   int sup;
	   int chek=0;
	   
	   printf("donner un nomber supprimer : ");
	   scanf("%d",&sup);
	   for(i=0;i<k;i++){
	   	if(T[i].identifiant==sup){
	   		for(j=i;j<k-1;j++){
	   			T[j]=T[j+1];
	   		
			   }k--;
			   chek=1;
		   }
	   }
	   if(chek==0){
	   		printf("Aucun reponse supprimer  \n");
	   } else {
	   	    printf(" identique  supprimer     \n");
	   }

}
//Rechercher les Tâches :
void Rechidentique(){
					int id;
					printf("donner un nomber Rechercher une tâche par son Identifiant : ");
					scanf("%d",&id);
					int chek=0;
					for(i=0;i<k;i++){
						if(T[i].identifiant==id){
							printf("     Identifiant      |        Titre         |     Description              |   Deadline         |  Status          |\n");
		                    printf("        %d             |        %s           |        %s               |   %d / %d / %d    |   %s        |\n",T[i].identifiant,T[i].titre,T[i].description,T[i].line.jours,T[i].line.moins,T[i].line.annne ,T[i].status);

//						    printf("---------------------------------------identifiant : %d\n",T[i].identifiant);
//				     	   	printf("---------------------------------------titre : %s \n",T[i].titre);
//				     	   	printf("---------------------------------------description : %s\n",T[i].description);
//				     	   	printf("---------------------------------------deadline : %d / %d / %d\n",T[i].line.jours,T[i].line.moins,T[i].line.annne);
//				     	   	printf("---------------------------------------status : %s\n",T[i].status);
				     	   	chek=1;
						}
						}
						if(chek==0){
							printf(" Aucun tachee recherche ----------------------------\n");
						}
}
//Rechercher une tâche par son Titre
void RechTitre(){
				 char titre[50];
				    int chek = 0;
				    printf("Rechercher une tâche par son titre : ");
				    scanf(" %49[^\n]", titre);
				    printf("  Identifiant  |     Titre      |   Description          |   Deadline     |  Status             |\n");
				    for ( i = 0; i < k; i++) {
				        if (strcmp(T[i].titre, titre) == 0) {
		                        printf(" %d                |%s             |%s|%d / %d / %d           |%s            |\n",T[i].identifiant,T[i].titre,T[i].description,T[i].line.jours,T[i].line.moins,T[i].line.annne ,T[i].status);

//							printf("-------------------------------------Identifiant : %d\n", T[i].identifiant);
//				            printf("-------------------------------------Titre : %s\n", T[i].titre);
//				            printf("-------------------------------------Description : %s\n", T[i].description);
//				            printf("-------------------------------------Deadline : %d / %d / %d\n", T[i].line.jours, T[i].line.moins, T[i].line.annne);
//				            printf("-------------------------------------Statut : %s\n", T[i].status);
				            chek = 1;
				        }
				    }
				
				    if (chek == 0) {
				        printf("Aucun titre trouvé.\n");
				    }
}
// Menu Recherche par tache identifiant et titre
void Rech(){
	        printf(" ------------------------------------------- Menu Recherche --------------------------------------------\n");
            printf(" *                                         Rechercher les Tâches :                                     *\n");
            printf(" *                                       1-Rechercher une tâche par son Identifiant                    *\n");
            printf(" *                                       2-Rechercher une tâche par son Titre                          *\n");
			printf(" *                                       0-return                                                      *\n");
			printf(" *-----------------------------------------------------------------------------------------------------*\n");
					     affiche();
						int c;
					    printf("donner un choix : ");
					    scanf("%d",&c);
					    if(c==1){
					    	system("cls");
					    	Rechidentique();
						}
						else if(c==2){
							system("cls");
							RechTitre();
						}else{
							system("cls");
							 main();
						}
						Rech();

}
//Statistiques
//Afficher le nombre total des tâches.

 void nobmretotal(){
 	affiche();
 	printf("le nombre total des tâches : %d\n",k);
 }
 //Afficher le nombre de tâches complètes et incomplètes.
 void tachecomp(){
 	                     int inc=0,comp=0;
 	                     for(i=0;i<k;i++){
 	                     	if(strcmp(T[i].status,"REALISER")==0 || strcmp(T[i].status,"ENCOURS")==0){
 	                     		  inc++;
							  }
						    if(strcmp(T[i].status,"FINALISE")==0) {
							  	comp++;
							  }
						  }
						    
				   printf("------------------------------------------------------------------------------------------\n");
				   printf("---------------------------le nombre de tâches:         ----------------------------------\n");
				   printf("------------------------------------complètes  :   %d   ----------------------------------\n",comp);
				   printf("-----------------------------------incomplètes   :   %d------------------------------------\n",inc);
				   		
			
				    
 	                
 }
 //affiche le nombre de jours restants jusqu'au délai de chaque tâche.
 void nombrejours(){
 	// biblio time.h 
                     time_t t=time(NULL);
                     // struct sur time.h 
                     struct tm dt=*localtime(&t);
                     int j=dt.tm_mday;
                     int m=dt.tm_mon+1;
                     int a=dt.tm_year+1900;
                     for(i=0;i<k;i++){
                    int jours = ((T[i].line.annne-a) * 365 +
					           (T[i].line.moins-m) * 30 + 
					                (T[i].line.jours-j));
                   printf("------------------------------------------------------------------------------------------\n");
				   printf("---------------------------nombre de jours restants:         ----------------------------------\n");
				   printf("------------------------------------identique  :   %d   ----------------------------------\n",T[i].identifiant);
				   printf("-------------------------------------status   :   %s------------------------------------\n",T[i].status); 
				   printf("-------------------------------------Jours restants : %d------------------------------------\n",jours);                 
                      
					 }
 
 }
 
 //  le menu de statistiques
void afficherMenuStatistiques() {
    printf(" -------------------------------------- Menu Statistiques ----------------------------------------\n");
    printf(" *                      Choisissez une option parmi les suivantes :                              *\n");
    printf(" *                   1 - Afficher le nombre total de tâches                                      *\n");
    printf(" *                   2 - Afficher le nombre de tâches complètes et incomplètes                   *\n");
    printf(" *                   3-Afficher le nombre de jours restants jusqu'au délai de chaque tâche.      *\n");
    printf(" *                   0 - return                                                                  *\n");
    printf(" *-----------------------------------------------------------------------------------------------*\n");
    
								                      int choixStatistiques;
										              printf("Saisissez votre choix : ");
										              scanf("%d", &choixStatistiques);
										                switch (choixStatistiques) {
										                    case 1:
										                    	system("cls");
										                        nobmretotal();
										                         afficherMenuStatistiques();
										                        break;
										                    case 2:
										                    	system("cls");
										                        tachecomp();
										                        afficherMenuStatistiques();
										                        break;
										                    case 3:
										                    	  system("cls");
															      nombrejours();
															      afficherMenuStatistiques();
															      break;
										                    case 0:
										                    	system("cls");
															     main();
										                        break;
										                    default:
										                        printf("Choix invalide. Veuillez réessayer.\n");
										                }
}

//Menuprancioal
 
int main(){

	int choix;
 do{
 	       	printf(" *-----------------------------------------------------------------------------------------------------*\n");
 	       	printf(" *------------------------------------         GESTION        -----------------------------------------*\n");
 	       	printf(" *------------------------------------          TO DO         -----------------------------------------*\n");
 	       	printf(" *-----------------------------------------------------------------------------------------------------*\n");
	   		printf(" ------------------------------------------- Menu Principale -------------------------------------------\n");
            printf(" *                                    Entre votre choix de list suivant :                              *\n");
            printf(" *                                       1-Ajouter une nouvelle tâche                                  *\n");
            printf(" *                                       2-Afficher la liste de toutes les tâches                      *\n");
            printf(" *                                       3-Modifier une tâche                                          *\n");
            printf(" *                                       4-Supprimer une tâche par identifiant                         *\n");
            printf(" *                                       5-Rechercher les Tâches                                       *\n");
            printf(" *                                       6-Statistiques                                                *\n");
			printf(" *                                       0-Quitter                                                     *\n");
			printf(" *-----------------------------------------------------------------------------------------------------*\n");
                         
								   	printf("donner un choix :");
								   	scanf("%d",&choix);
								   	switch(choix){
									   	case 1 :     system("cls");
										             MenuAjourt();
											         break;
									   	case 2 :     operationTri();
													 break;
								   		case 3 :     system("cls");
										             Modifier();
										             break;
								   		case 4 :     affiche();
										             supprimer(); 
										             main();
										             break;
								   		case 5:      system("cls");
										             Rech();
										             break;
								   		case 6:      system("cls");
							                         afficherMenuStatistiques();
										             break;                 
										case 0 :    
										            
										            
										            system("cls");
										            printf("Quitter");
										            return 0;
										         
										             break;
										             
									   }
								   }while(choix!=0);
								     
								   
	return 0;
}
