    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    /*---------------------------------------------------Declaration---------------------------------------------------*/
    typedef struct{
        char id[15];
        char nom[15];
        char prenom[15];
        char date_Naissance[20];
        char departement[20];
        float noteGeneral;

    }etudiant;
    etudiant etudiants_List[50];

    int countEtudiat=0;
    char departementChoix[20];
    int existeName;

        float math=0;
        float physique=0;
        float chimique=0;
        float francais=0;
        float anglais=0;


    /*---------------------------------------------------Fonction Menu---------------------------------------------------*/
    void Menu(){

    char choix[2];
    int N;
     do{
         printf("---------------------------Menu---------------------------\n");
         printf("1.Ajouter un etudiant :\n");
         printf("2.Modifier ou supprimer un étudiant :\n");
          printf("3.Afficher les details de tous les etudiants :\n");
         printf("4.Calculer le moyenne de chaque departement et de l'universite :\n");
         printf("5.Statistiques :\n");
         printf("6.Rechercher un étudiant :\n");
         printf("7.Trier les étudiants :\n");
         printf("0.pour quittez le programme. :\n");

         printf("choisi un nombre:");
         scanf("%s",&choix);
         clearConsole();
        if(choix[0]>=48&&choix[0]<=55){

            N=choix[0]-'0';

             // Switch case Ajout
             switch(N){
                   case 1:
                        ajoutEtudiant();
                        break;
                   case 2:
                       modification_Supression();
                       break;
                   case 3:
                       affichageEtudiants();
                       break;
                   case 4:
                       CalculationMoyenne();
                       break;
                   case 5:
                       statistique();
                       break;
                   case 6:
                       rechercherEtudiant();
                       break;
                    case 7:
                       trierOptions();
                       break;
                   case 0:
                       printf("le programme est quitter.");
                       break;
           }

        }else{
            printf("veillez saisir un nombre entre 1 et 7.\n");
        }
    }while(N!=0);
    }


    /*---------------------------------------------------Fonction Clear Console---------------------------------------------------*/
    void clearConsole(){
        system("@cls||clear");
    }

    /*---------------------------------------------------Fonction D'ajoute---------------------------------------------------*/
    void ajoutEtudiant(){
        printf("saisir le numero unique d'etudiant:");
        scanf("%s",&etudiants_List[countEtudiat].id);
        printf("saisir le nom d'etudiant:");
        scanf(" %[^\n]",etudiants_List[countEtudiat].nom);
        printf("saisir le prenom d'etudiant:");
        scanf(" %[^\n]",etudiants_List[countEtudiat].prenom);
        printf("saisir la date de naissance d'etudiant:");
        scanf(" %[^\n]",etudiants_List[countEtudiat].date_Naissance);
        departementSwitchPrincipale();
        strcpy(etudiants_List[countEtudiat].departement,departementChoix);
        printf("saisir la note general d'etudiant:");
        scanf("%f",&etudiants_List[countEtudiat].noteGeneral);
        countEtudiat++;
    }


    /*---------------------------------------------------Fonction departement switch ---------------------------------------------------*/
    void departementSwitchPrincipale(){

         int choix;
         printf("-Departement Choix-\n");
         printf("1.Math :\n");
         printf("2.physique :\n");
         printf("3.chimique :\n");
         printf("4.francais :\n");
         printf("5.anglais :\n");
         printf("choisi un nombre:");
         scanf("%d",&choix);
               switch(choix){
                  case 1:
                      strcpy(departementChoix,"math");
                      math++;
                      break;
                  case 2:
                       strcpy(departementChoix,"physique");
                       physique++;
                       break;
                  case 3:
                       strcpy(departementChoix,"chimique");
                       chimique++;
                       break;
                  case 4:
                       strcpy(departementChoix,"francais");
                       francais++;
                       break;
                  case 5:
                      strcpy(departementChoix,"anglais");
                      anglais++;
                      break;

                 }
             }


    /*---------------------------------------------------Fonction check etudiant ---------------------------------------------------*/
        void checkEtudiant(){
            char Nom[15];
            char Prenom[15];
            printf("saisir le Nom:");
            scanf("%s",&Nom);
            printf("saisir le Prenom:");
            scanf("%s",&Prenom);
            existeName=-1;
                for(int i=0;i<countEtudiat;i++){
                    if(!strcmp(Nom,etudiants_List[i].nom)&&!strcmp(Prenom,etudiants_List[i].prenom)){
                    existeName=i;
                    break;
                    }
                 }
         }


    /*---------------------------------------------------Fonction Modification et suppression---------------------------------------------------*/
    void modification_Supression(){
         int choix;
         printf("---------------------------Modification Choix---------------------------\n");
         printf("1.Modifier un etudiant :\n");
         printf("2.supprimer un etudiant :\n");
         printf("choisi un nombre:");
         scanf("%d",&choix);
           switch(choix){
               case 1:
                   modificationEtudiant();
                   break;
               case 2:
                   supprimertudiant();
                   break;
           }
       }


    /*---------------------------------------------------Fonction Modification---------------------------------------------------*/
    void modificationEtudiant(){
        checkEtudiant();
        if (existeName>=0){
            modification_Switch();
        }else{
            printf("il ya aucun etudiant avec ce nom et prenom.\n");
        }
    }


    /*---------------------------------------------------Fonction Switch Modification---------------------------------------------------*/
    void modification_Switch(){
        int choix;
         printf("---------------------------Modification Choix---------------------------\n");
         printf("1.Modifier le nom :\n");
         printf("2.Modifier le prenom :\n");
         printf("3.Modifier la date de naissance :\n");
         printf("4.Modifier le departement :\n");
         printf("5.Modifier la note general :\n");
         printf("0.Routour au menu principale. :\n");
         printf("choisi un nombre:");
         scanf("%d",&choix);
               switch(choix){
                   case 1:
                        modificationNom();
                   break;
                   case 2:
                        modificationPrenom();
                   break;
                   case 3:
                        modificationDate();
                   break;
                   case 4:
                        modificationDepartement();
                   break;
                   case 5:
                        modificationNote();
                   break;

               }
           }


    /*---------------------------------------------------Fonction modification nom---------------------------------------------------*/

    void modificationNom(){
        char NomModife[15];
        printf("saisir le nouveau nom:");
        scanf("%s",&NomModife);
        strcpy(etudiants_List[existeName].nom,NomModife);

    }

    /*---------------------------------------------------Fonction modification prenom---------------------------------------------------*/

    void modificationPrenom(){
        char prenomModife[15];
        printf("saisir le nouveau prenom:");
        scanf("%s",&prenomModife);
        strcpy(etudiants_List[existeName].prenom,prenomModife);
    }

    /*---------------------------------------------------Fonction modification date naissance---------------------------------------------------*/

    void modificationDate(){
        char date_Naissance_Modife[15];
        printf("saisir la nouveau date de naissance:");
        scanf("%s",&date_Naissance_Modife);
        strcpy(etudiants_List[existeName].date_Naissance,date_Naissance_Modife);
    }

    /*---------------------------------------------------Fonction modification departement---------------------------------------------------*/

    void modificationDepartement(){
        char departModife[20];
        printf("saisir le nouveau departement:");
        scanf("%s",&departModife);
        strcpy(etudiants_List[existeName].departement,departModife);
    }


    /*---------------------------------------------------Fonction modification note---------------------------------------------------*/

    void modificationNote(){
        float noteModife;
        printf("saisir la nouveau note:");
        scanf("%f",&noteModife);
        etudiants_List[existeName].noteGeneral=noteModife;
    }

    /*---------------------------------------------------Fonction Suppresion---------------------------------------------------*/
    void supprimertudiant(){
         checkEtudiant();
          if(existeName>=0){
              for(int i=existeName;i<countEtudiat;i++){
                    strcpy(etudiants_List[i].id,etudiants_List[i+1].id);
                    strcpy(etudiants_List[i].nom,etudiants_List[i+1].nom);
                    strcpy(etudiants_List[i].prenom,etudiants_List[i+1].prenom);
                    strcpy(etudiants_List[i].date_Naissance,etudiants_List[i+1].date_Naissance);
                    strcpy(etudiants_List[i].departement,etudiants_List[i+1].departement);
                    etudiants_List[i].noteGeneral=etudiants_List[i+1].noteGeneral;

          }
                    countEtudiat --;
          }else{
                printf("il ya aucun contact avec ce nm et prenom.\n");
          }
    }

    /*---------------------------------------------------Fonction Afficher tous les etudiant---------------------------------------------------*/
    void affichageEtudiants(){
       if(countEtudiat>0){
            for(int i=0;i<countEtudiat;i++){
                printf("==Etudiant numero : %d==\n",i);
                printf("Le nombre unique:%s\n",etudiants_List[i].id);
                printf("Le nom :%s\n",etudiants_List[i].nom);
                printf("Le prenom :%s\n",etudiants_List[i].prenom);
                printf("La date de naissance:%s\n",etudiants_List[i].date_Naissance);
                printf("Le departement:%s\n",etudiants_List[i].departement);
                printf("Le la note generale:%.2f\n",etudiants_List[i].noteGeneral);

            }

            }else{
                printf("il ya aucun etudiant.\n");
            }
    }


    /*---------------------------------------------------Fonction calculer le moyenne---------------------------------------------------*/
    void CalculationMoyenne(){
        moyenneDuniversite();
        moyenneDeChaqueDepartement();
    }


    /*---------------------------------------------------Fonction moyenne universite ---------------------------------------------------*/
    void moyenneDuniversite(){
        float moyenneUnevirsite=0;
        for(int i=0;i<countEtudiat;i++){
            moyenneUnevirsite+=etudiants_List[i].noteGeneral;
        }
            printf("le moyenne generale de de l'universite est:%.2f\n",moyenneUnevirsite/countEtudiat);
    }

    /*---------------------------------------------------Fonction moyenne de chaque departement ---------------------------------------------------*/
    void moyenneDeChaqueDepartement(){
        float totalMath=0;
        float totalPhysique=0;
        float totalChimic=0;
        float totalFrancais=0;
        float totalAnglais=0;
        for(int i=0;i<countEtudiat;i++){
                if(strcmp(etudiants_List[i].departement,"math")==0){
                    totalMath+=etudiants_List[i].noteGeneral;
                }else if(strcmp(etudiants_List[i].departement,"physique")==0){
                    totalPhysique+=etudiants_List[i].noteGeneral;
                }else if(strcmp(etudiants_List[i].departement,"chimic")==0){
                    totalChimic+=etudiants_List[i].noteGeneral;
                }else if(strcmp(etudiants_List[i].departement,"francais")==0){
                    totalFrancais+=etudiants_List[i].noteGeneral;
                }else{
                    totalAnglais+=etudiants_List[i].noteGeneral;
                }
            }
                printf("Le moyenne total de Math %.2f\n",totalMath/math);
                printf("Le moyenne total de physique %.2f\n",totalPhysique/physique);
                printf("Le moyenne total de chimic %.2f\n",totalChimic/chimique);
                printf("Le moyenne total de francais %.2f\n",totalFrancais/francais);
                printf("Le moyenne total de anglais %.2f\n",totalAnglais/anglais);

    }


    /*---------------------------------------------------Fonction statistique Options---------------------------------------------------*/
    void departementSwitchSecondaire(){
     int choix;
        printf("---------------------------Departement Choix---------------------------\n");
        printf("1.Math :\n");
        printf("2.physique :\n");
        printf("3.chimique :\n");
        printf("4.francais :\n");
        printf("5.anglais :\n");
        printf("choisi un nombre:");
        scanf("%d",&choix);
           switch(choix){
                case 1:
                    strcpy(departementChoix,"math");
                    break;
               case 2:
                    strcpy(departementChoix,"physique");
                    break;
               case 3:
                    strcpy(departementChoix,"chimique");
                    break;
               case 4:
                    strcpy(departementChoix,"francais");
                    break;
               case 5:
                    strcpy(departementChoix,"anglais");
                    break;
                }
            }


    /*---------------------------------------------------Fonction statistique Options---------------------------------------------------*/
    void statistique(){
            int choix;
            printf("1.Afficher le nombre total d'étudiants inscrits :\n");
            printf("2.Afficher le nombre d'étudiants dans chaque département :\n");
            printf("3.Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil :\n");
            printf("4.Afficher les 3 étudiants ayant les meilleures notes :\n");
            printf("5.Afficher le nombre d'étudiants ayant réussi dans chaque département :\n");
            printf("saisir un choix:\n");
            scanf("%d",&choix);
             switch(choix){
                  case 1:
                       afficheNombreTotal();
                       break;
                   case 2:
                       afficheNombreTotal_Departement();
                       break;
                   case 3:
                       afficheEtudiantSuperieur_parSeuil();
                       break;
                   case 4:
                       afficheTroisMeilleures();
                       break;
                   case 5:
                       afficheEtudiantsReussi_Departement();
                       break;
            }
        }

    /*---------------------------------------------------Fonction Affichage Nombre Total---------------------------------------------------*/

    void afficheNombreTotal(){
        printf("le nombre total des etudiants est:%d",countEtudiat);
    }

    /*---------------------------------------------------Fonction Affichage Nombre Total dans chaque departement---------------------------------------------------*/

    void afficheNombreTotal_Departement(){
        printf("le nombre total des etudiants dans le departement math est:%d.\n",math);
        printf("le nombre total des etudiants dans le departement physique est:%d.\n",physique);
        printf("le nombre total des etudiants dans le departement chimique est:%d.\n",chimique);
        printf("le nombre total des etudiants dans le departement francais est:%d.\n",francais);
        printf("le nombre total des etudiants dans le departement anglais est:%d.\n",anglais);
    }

    /*---------------------------------------------------Fonction Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil---------------------------------------------------*/

    void afficheEtudiantSuperieur_parSeuil(){
       float seuil=0;
       printf("saisir le seuil:");
       scanf("%f",&seuil);
           for(int i=0;i<countEtudiat;i++){
                if(etudiants_List[i].noteGeneral>=seuil){
                    printf("Le nombre unique:%s\n",etudiants_List[i].id);
                    printf("Le nom :%s\n",etudiants_List[i].nom);
                    printf("Le prenom :%s\n",etudiants_List[i].prenom);
                    printf("La date de naissance:%s\n",etudiants_List[i].date_Naissance);
                    printf("Le departement:%s\n",etudiants_List[i].departement);
                    printf("Le la note generale:%.2f\n",etudiants_List[i].noteGeneral);
                }

            }

        }

    /*---------------------------------------------------Fonction Afficher les 3 étudiants ayant les meilleures notes---------------------------------------------------*/

    void afficheTroisMeilleures(){
       float tableauTri[30];
           for(int i=0;i<countEtudiat;i++){
           tableauTri[i]=etudiants_List[i].noteGeneral;
           }
           for(int i=0;i<countEtudiat;i++){
               if(tableauTri[i]<tableauTri[i+1]){
                 tableauTri[i]=tableauTri[i]+tableauTri[i+1];
                tableauTri[i+1]=tableauTri[i]-tableauTri[i+1];
                tableauTri[i]=tableauTri[i]-tableauTri[i+1];
               }
           }
          for(int i;i<3;i++){
            for(int j=0;j<countEtudiat;j++){
                if(tableauTri[i]==etudiants_List[j].noteGeneral){
                    printf("Le nombre unique:%s\n",etudiants_List[j].id);
                    printf("Le nom :%s\n",etudiants_List[j].nom);
                    printf("Le prenom :%s\n",etudiants_List[j].prenom);
                    printf("La date de naissance:%s\n",etudiants_List[j].date_Naissance);
                    printf("Le departement:%s\n",etudiants_List[j].departement);
                    printf("Le la note generale:%.2f\n",etudiants_List[j].noteGeneral);
                }
            }
          }
       }



    /*---------------------------------------------------Fonction Afficher le nombre d'étudiants ayant réussi dans chaque département---------------------------------------------------*/

    void afficheEtudiantsReussi_Departement(){

        departementSwitchSecondaire();
      for(int i=0;i<countEtudiat;i++){
            if(!strcmp(etudiants_List[i].departement,departementChoix )&& etudiants_List[i].noteGeneral>=10){
                printf("Le nombre unique:%s\n",etudiants_List[i].id);
                printf("Le nom :%s\n",etudiants_List[i].nom);
                printf("Le prenom :%s\n",etudiants_List[i].prenom);
                printf("La date de naissance:%s\n",etudiants_List[i].date_Naissance);
                printf("Le departement:%s\n",etudiants_List[i].departement);
                printf("Le la note generale:%.2f\n",etudiants_List[i].noteGeneral);
            }
       }
    }


    /*---------------------------------------------------Fonction Recherche---------------------------------------------------*/
    void rechercherEtudiant(){

       int choix;
        printf("---------------------------recherche Choix---------------------------\n");
        printf("1.Rechercher un étudiant par son nom :\n");
        printf("2.Afficher la liste des étudiants inscrits dans un département spécifique :\n");
        printf("choisi un nombre:");
        scanf("%d",&choix);
           switch(choix){
            case 1:
                // Rechercher un étudiant par son nom.
               AfficherEtudiant();
               break;
            case 2:
                // Afficher la liste des étudiants inscrits dans un département spécifique.
               AfficherEtudiant_chaque_departement();
               break;
            }
        }


    /*---------------------------------------------------Fonction recherche etudiant ---------------------------------------------------*/
    void AfficherEtudiant(){
            checkEtudiant();
            printf("Le nombre unique:%s\n",etudiants_List[existeName].id);
            printf("Le nom :%s\n",etudiants_List[existeName].nom);
            printf("Le prenom :%s\n",etudiants_List[existeName].prenom);
            printf("La date de naissance:%s\n",etudiants_List[existeName].date_Naissance);
            printf("Le departement:%s\n",etudiants_List[existeName].departement);
            printf("Le la note generale:%.2f\n",etudiants_List[existeName].noteGeneral);
    }

    /*---------------------------------------------------Fonction recherche les etudiants d'un departement ---------------------------------------------------*/
    void AfficherEtudiant_chaque_departement(){
      departementSwitchSecondaire();

           for(int i=0;i<countEtudiat;i++){
                if(!strcmp(etudiants_List[i].departement,departementChoix)){
                    printf("Le nombre unique:%s\n",etudiants_List[i].id);
                    printf("Le nom :%s\n",etudiants_List[i].nom);
                    printf("Le prenom :%s\n",etudiants_List[i].prenom);
                    printf("La date de naissance:%s\n",etudiants_List[i].date_Naissance);
                    printf("Le departement:%s\n",etudiants_List[i].departement);
                    printf("Le la note generale:%.2f\n",etudiants_List[i].noteGeneral);
                }
           }
        }



    /*---------------------------------------------------Fonction Tri---------------------------------------------------*/
    void trierOptions(){

    }

    /*---------------------------------------------------Fonction Main---------------------------------------------------*/
    int main(){
    Menu();

    }
