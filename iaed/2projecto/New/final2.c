/* 		PROJECTO 2 - final.c
 * 
 * 78093 - Goncalo Santos
 * 78328 - Pedro Duarte
 * 79112 - Goncalo Fialho
 * 
 * */




/***************MAIN***************/

int main() {
	int N_USERS,u;
	char input[MAXINPUT];
	User ArrayUsers;
	scanf("%d", &N_USERS);
	ArrayUsers  = calloc(N_USERS, sizeof(struct user));
	
	while (1) {
		scanf("%s",input);
		if (strcmp(input,"send") == 0) 
			send(ArrayUsers);
			
		if (strcmp(input,"process") == 0) {
			scanf("%d",&u);
			process(ArrayUsers,u);
		}
			
		if (strcmp(input,"list") == 0) {
		 	scanf("%d",&u);
			list(ArrayUsers,u);
		}

		if (strcmp(input,"kill") == 0){
			scanf("%d",&u);
			kill(ArrayUsers,u);
		}
		if (strcmp(input,"listsorted") == 0)  {
			scanf("%d", &u);
			listSorted(ArrayUsers,u);
		}
	
		if (strcmp(input,"quit") == 0) {
			for(u=0;u<N_USERS;u++)
				kill(ArrayUsers,u);
			free(ArrayUsers);
			return EXIT_SUCCESS;
		} 
	
	}
	free(ArrayUsers);
	return EXIT_FAILURE;
}

