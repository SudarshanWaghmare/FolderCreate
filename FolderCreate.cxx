#include"FolderCreate.hxx"

int ITK_user_main(int argc,	char* argv[]) {
	int status;


	char* user = ITK_ask_cli_argument("-u=");
	char* password = ITK_ask_cli_argument("-p=");
	char* group = ITK_ask_cli_argument("-g=");


	status = ITK_init_module(user, password, group); //"infodba"
	if (status == ITK_ok) {
		printf("Login Successful.\n");
	}
	else {
		printf("Failed to Login.\n");
	}

	tag_t home_folder;
	status= SA_ask_user_home_folder(user, &home_folder);
		
	tag_t type = NULLTAG;
	status= TCTYPE_ask_type("Folder", &type);

	tag_t create_input;
	status = TCTYPE_construct_create_input(type, &create_input);

	int AOM_set_value_string(create_input, "object_name", "Folder by ITK");

	tag_t new_folder = NULLTAG;
	status= TCTYPE_create_object(create_input, &new_folder);

	status = AOM_save_with_extensions(new_folder);	
	if (status == ITK_ok) {
		printf("Folder created Successful.\n");
	}
	else {
		printf("Failed to create folder.\n");
	}

	status = ITK_exit_module(true); // log out fro teamcenter
	
	(void)_getch();
	return ITK_ok;
}
