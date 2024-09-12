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

        int math=0;
        int physique=0;
        int chimique=0;
        int francais=0;
        int anglais=0;


    /*---------------------------------------------------Fonction Menu---------------------------------------------------*/
    void Menu(){
    char choix[2];
    int N;
     do{
         printf("---------------------------Gestion des etudiants---------------------------\n");
         printf("1.Ajouter un etudiant :\n");
         printf("2.Modifier ou supprimer un etudiant :\n");
          printf("3.Afficher les details de tous les etudiants :\n");
         printf("4.Calculer le moyenne de chaque departement et de l'universite :\n");
         printf("5.Statistiques :\n");
         printf("6.Rechercher un etudiant :\n");
         printf("7.Trier les etudiants :\n");
         printf("0.pour quittez le programme. :\n");

         printf("choisi un nombre:");
         scanf("%s",choix);
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
            Menu();
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
      for(int i=countEtudiat-1;i>=0;i--){
        if(strcmp(etudiants_List[countEtudiat].id,etudiants_List[i].id)==0){
         printf("=> ce nombre unique est deja existe vous pouvez saisir un autre nombre.\n");
         ajoutEtudiant();
        return;
        }
      }
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
         printf("0.Routour au menu principale :\n");

         printf("choisi un nombre:");
         scanf("%d",&choix);
           switch(choix){
               case 1:
                   modificationEtudiant();
                   break;
               case 2:
                   supprimertudiant();
                   break;
               case 0:
                   Menu();
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
         printf("0.Routour au menu principale :\n");
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
                   case 0:
                        Menu();
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
                printf("==Etudiant numero : %d==\n",i+1);
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
            if(countEtudiat>0){
                printf("le moyenne generale de l'universite est:%.2f\n",moyenneUnevirsite/countEtudiat);
            }else{
                printf("il ya aucun etudiant dans l'universite.\n");

            }
    }

    /*---------------------------------------------------Fonction moyenne de chaque departement ---------------------------------------------------*/
    void moyenneDeChaqueDepartement(){
        float totalMath=0;
        float totalPhysique=0;
        float totalChimic=0;
        float totalFrancais=0;
        float totalAnglais=0;
       if(countEtudiat>0){
         for(int i=0;i<countEtudiat;i++){
                if(strcmp(etudiants_List[i].departement,"math")==0){
                    totalMath+=etudiants_List[i].noteGeneral;
                    break;
                }else if(strcmp(etudiants_List[i].departement,"physique")==0){
                    totalPhysique+=etudiants_List[i].noteGeneral;
                    break;
                }else if(strcmp(etudiants_List[i].departement,"chimic")==0){
                    totalChimic+=etudiants_List[i].noteGeneral;
                    break;

                }else if(strcmp(etudiants_List[i].departement,"francais")==0){
                    totalFrancais+=etudiants_List[i].noteGeneral;
                    break;
                }else{
                    totalAnglais+=etudiants_List[i].noteGeneral;
                    break;
                }
            }
              if(totalMath>0)
                printf("Le moyenne total de Math %.2f\n",totalMath/math);
              if (totalPhysique>0)
                printf("Le moyenne total de physique %.2f\n",totalPhysique/physique);
             if (totalChimic>0)
                printf("Le moyenne total de chimic %.2f\n",totalChimic/chimique);
             if (totalFrancais>0)
                printf("Le moyenne total de francais %.2f\n",totalFrancais/francais);
             if (totalAnglais>0)
                printf("Le moyenne total de francais %.2f\n",totalAnglais/anglais);
             if (totalAnglais==0 || totalFrancais==0 || totalFrancais==0 || totalFrancais==0){
                printf("il ya aucun etudiant dans les autre departements.\n");
                }
       }else{
           printf("il ya aucun etudiant dans tous les departements.\n");
       }

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
            printf("1.Afficher le nombre total d'etudiants inscrits :\n");
            printf("2.Afficher le nombre d'etudiants dans chaque departement :\n");
            printf("3.Afficher les etudiants ayant une moyenne generale superieure a un certain seuil :\n");
            printf("4.Afficher les 3 etudiants ayant les meilleures notes :\n");
            printf("5.Afficher le nombre d'etudiants ayant reussi dans chaque departement :\n");
            printf("0.Routour au menu principale :\n");

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
                   case 0:
                       Menu();
                       break;
            }
        }

    /*---------------------------------------------------Fonction Affichage Nombre Total---------------------------------------------------*/

    void afficheNombreTotal(){
        printf("le nombre total des etudiants est:%d.\n",countEtudiat);
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
       int noteExist = 1;

       printf("saisir le seuil:");
       scanf("%f",&seuil);
           for(int i=0;i<countEtudiat;i++){
                if(etudiants_List[i].noteGeneral>=seuil){
                    printf("==Etudiant numero : %d==\n",i+1);
                    printf("Le nombre unique:%s\n",etudiants_List[i].id);
                    printf("Le nom :%s\n",etudiants_List[i].nom);
                    printf("Le prenom :%s\n",etudiants_List[i].prenom);
                    printf("La date de naissance:%s\n",etudiants_List[i].date_Naissance);
                    printf("Le departement:%s\n",etudiants_List[i].departement);
                    printf("Le la note generale:%.2f\n",etudiants_List[i].noteGeneral);
                    noteExist = 0;
                }

            }
            if(noteExist == 1){
                    printf("il ya aucun etudiant superieure a ce seuil .\n");

                }

        }

    /*--------------------------------Fonction Afficher les 3 étudiants ayant les meilleures notes-------------------------------*/

    void afficheTroisMeilleures(){
      if(countEtudiat>=3){
         float tableauTri[30];
           for(int i=0;i<countEtudiat;i++){
           tableauTri[i]=etudiants_List[i].noteGeneral;
           }
           //triange des note
           for(int i=0;i<countEtudiat;i++){
               if(tableauTri[i]<tableauTri[i+1]){
                 tableauTri[i]=tableauTri[i]+tableauTri[i+1];
                tableauTri[i+1]=tableauTri[i]-tableauTri[i+1];
                tableauTri[i]=tableauTri[i]-tableauTri[i+1];
               }
           }
           // affichage

              for(int i=0;i<3;i++){
            for(int j=0;j<countEtudiat;j++){
                if(tableauTri[i]==etudiants_List[j].noteGeneral){
                    printf("==Etudiant numero : %d==\n",j+1);
                    printf("Le nombre unique:%s\n",etudiants_List[j].id);
                    printf("Le nom :%s\n",etudiants_List[j].nom);
                    printf("Le prenom :%s\n",etudiants_List[j].prenom);
                    printf("La date de naissance:%s\n",etudiants_List[j].date_Naissance);
                    printf("Le departement:%s\n",etudiants_List[j].departement);
                    printf("Le la note generale:%.2f\n",etudiants_List[j].noteGeneral);

            }
          }
        }
      }else{
      printf("Il n y en a pas assez des etudiants pour afficher les 3 meilleures notes.\n");
      }
       }



    /*-------------------------------Fonction Afficher le nombre d'étudiants ayant réussi dans chaque département-------------------------*/

    void afficheEtudiantsReussi_Departement(){

          departementSwitchSecondaire();
          int notExist=1;
          for(int i=0;i<countEtudiat;i++){
                if(strcmp(etudiants_List[i].departement,departementChoix )==0&& etudiants_List[i].noteGeneral>=10){
                      if(math>0)
                        printf("Le nombre d'étudiants ayant réussi dans departement Math: %d\n",math);
                      if (physique>0)
                        printf("Le nombre d'étudiants ayant réussi dans departement physique: %d\n",physique);
                     if (chimique>0)
                        printf("Le nombre d'étudiants ayant réussi dans departement chimique: %d\n",chimique);
                     if (francais>0)
                        printf("Le nombre d'étudiants ayant réussi dans departement francais: %d\n",francais);
                     if (anglais>0)
                        printf("Le nombre d'étudiants ayant réussi dans departement anglais: %d\n",anglais);

                        notExist=0;
                 }
           }

       if(notExist==1){
        printf("il y a aucun etudinat dans ce departement.\n");
       }
    }


    /*---------------------------------------------------Fonction Recherche---------------------------------------------------*/
    void rechercherEtudiant(){

       int choix;
        printf("---------------------------recherche Choix---------------------------\n");
        printf("1.Rechercher un etudiant par son nom :\n");
        printf("2.Afficher la liste des etudiants inscrits dans un departement specifique :\n");
        printf("0.Routour au menu principale :\n");

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
            case 0:
                Menu();
                break;
            }
        }


    /*---------------------------------------------------Fonction recherche etudiant par nom ---------------------------------------------------*/
    void AfficherEtudiant(){
            checkEtudiant();
          if(existeName>0){
              printf("Le nombre unique:%s\n",etudiants_List[existeName].id);
            printf("Le nom :%s\n",etudiants_List[existeName].nom);
            printf("Le prenom :%s\n",etudiants_List[existeName].prenom);
            printf("La date de naissance:%s\n",etudiants_List[existeName].date_Naissance);
            printf("Le departement:%s\n",etudiants_List[existeName].departement);
            printf("Le la note generale:%.2f\n",etudiants_List[existeName].noteGeneral);
          }else{
          printf("il ya aucun etudiant avec ce nom et prenom.\n");
          }
    }

    /*---------------------------------------------------Fonction recherche les etudiants d'un departement ---------------------------------------------------*/
    void AfficherEtudiant_chaque_departement(){
      departementSwitchSecondaire();
      int notExist=1;
           for(int i=0;i<countEtudiat;i++){
                if(strcmp(etudiants_List[i].departement,departementChoix)==0){
                    printf("==Etudiant numero : %d==\n",i+1);
                    printf("Le nombre unique:%s\n",etudiants_List[i].id);
                    printf("Le nom :%s\n",etudiants_List[i].nom);
                    printf("Le prenom :%s\n",etudiants_List[i].prenom);
                    printf("La date de naissance:%s\n",etudiants_List[i].date_Naissance);
                    printf("Le departement:%s\n",etudiants_List[i].departement);
                    printf("Le la note generale:%.2f\n",etudiants_List[i].noteGeneral);
                    notExist=0;
                 }
           }
           if(notExist==1){
                 printf("il y a aucun etudinat dans ce departement.\n");       }
            }



    /*---------------------------------------------------Fonction Tri---------------------------------------------------*/
    void trierOptions(){
       int choix;
            printf("1.Tri alphabetique des etudiants en fonction de leur nom :\n");
            printf("2.Tri des etudiants par moyenne generale :\n");
            printf("3.Tri des etudiants selon leur statut de reussite :\n");
            printf("saisir un choix:\n");
            scanf("%d",&choix);
             switch(choix){
                  case 1:
                       triNom();
                       break;
                   case 2:
                       triMoyenne();
                       break;
                   case 3:
                       triReussite();
                       break;

            }
    }

    /*---------------------------------------------------Fonction tri du nom---------------------------------------------------*/
    void triNom(){

            for (int i = 0; i < countEtudiat-1; i++) {
                if (strcmp(etudiants_List[i].nom,etudiants_List[i+1].nom)>0) {
                    // Swap
                    etudiant temp = etudiants_List[i];
                    etudiants_List[i] = etudiants_List[i + 1];
                    etudiants_List[i + 1] = temp;
                }
            }
           affichageEtudiants();

    }

    /*---------------------------------------------------Fonction tri du note---------------------------------------------------*/
    void triMoyenne(){
         for (int i = 0; i < countEtudiat; i++) {
              for(int j=i+1;j<countEtudiat;j++){

                  if (etudiants_List[i].noteGeneral<etudiants_List[j].noteGeneral) {
                    // Swap
                    etudiant temp = etudiants_List[i];
                    etudiants_List[i] = etudiants_List[j ];
                    etudiants_List[j] = temp;
                }
              }
            }
          affichageEtudiants();


    }

    /*---------------------------------------------------Fonction Tri des étudiants selon leur statut de réussite ---------------------------------------------------*/
    void triReussite(){
     int notExist=1;
     for (int i = 0; i < countEtudiat; i++) {
              for(int j=i+1;j<countEtudiat;j++){

                  if (etudiants_List[i].noteGeneral<etudiants_List[j].noteGeneral) {
                    // Swap
                    etudiant temp = etudiants_List[i];
                    etudiants_List[i] = etudiants_List[j ];
                    etudiants_List[j] = temp;
                }
              }
            }


            for(int i=0;i<countEtudiat;i++){
               if(etudiants_List[i].noteGeneral>=10){
                printf("==Etudiant numero : %d==\n",i+1);
                printf("Le nombre unique:%s\n",etudiants_List[i].id);
                printf("Le nom :%s\n",etudiants_List[i].nom);
                printf("Le prenom :%s\n",etudiants_List[i].prenom);
                printf("La date de naissance:%s\n",etudiants_List[i].date_Naissance);
                printf("Le departement:%s\n",etudiants_List[i].departement);
                printf("Le la note generale:%.2f\n",etudiants_List[i].noteGeneral);
                notExist=0;
               }

            }
            if (notExist==1){
                printf("il ya aucun etudiant.\n");

            }



    }

    /*---------------------------------------------------Fonction Main---------------------------------------------------*/
    int main(){
    Menu();

    }
