#include "file_methods.h"

void file_save_aux(t_itree *T, int id, FILE *fp){
    int i = 0;
    t_itree *aux;
    t_db *db;

    aux = ibt_search(T, id);
    if(aux){
        while((i < aux->n_db) && (aux->blocks[i]->id != id)) i++;
        db = aux->blocks[i];

        fprintf(fp, "%s", db->content);
        file_save_aux(T, db->next_id, fp);
    }
}

void file_save(t_itable **list, t_itree *T, char *filename){
    int id;
	t_itable *list_node;
    FILE *fp;

	list_node = it_search(*list, filename);
    if(list_node) {
		id = list_node->id;
        fp = fopen(filename, "w");
		file_save_aux(T, id, fp);
        printf("Arquivo '%s' salvo com sucesso\n", filename);
        fclose(fp);
    }
    else printf("Arquivo não encontrado\n");
}