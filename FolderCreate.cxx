#include"FolderCreate.hxx"

int ITK_user_main(int argc,	char* argv[]) {
	int status;


	char* user = ITK_ask_cli_argument("-u");
	char* password = ITK_ask_cli_argument("-p");
	char* group = ITK_ask_cli_argument("-g");


	status = ITK_init_module(user, password, group); //"infodba"
	if (status == ITK_ok) {
		printf("Login Successful.\n");
	}
	else {
		printf("Failed to Login.\n");
	}

	tag_t new_folder = NULLTAG;
	status = FL_create2("ITEM CERATED BY ITK", "Folder ", &new_folder);
	if (status == ITK_ok) {
		printf("Folder created Successful.\n");
	}
	else {
		printf("Failed to create folder.\n");
	}
	(void)_getch();
	return ITK_ok;
}