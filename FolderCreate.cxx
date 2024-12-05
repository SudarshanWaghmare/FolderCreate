#include"FolderCreate.hxx"

int ITK_user_main(int argc,	char* argv[]) {
	int status;


	char* user = ITK_ask_cli_argument("-u=");
	char* password = ITK_ask_cli_argument("-p=");
	char* group = ITK_ask_cli_argument("-g=");


	status = ITK_init_module(user, password, group); //"infodba"
	if (status == ITK_ok) {
		printf("\n-----Login Successful.-----\n");
	}
	else {
		printf("\n-----Failed to Login.-----\n");
	}

	tag_t home_folder;
	status= SA_ask_user_home_folder(user, &home_folder);
	if (status == ITK_ok) {
		printf("\n-----User home folder found Successful.-----\n");
	}
	else {
		printf("\n-----Failed to get user home.-----\n");
	}
		
	tag_t type = NULLTAG;
	status= TCTYPE_ask_type("Folder", &type);
	if (status == ITK_ok) {
		printf("\n-----User home folder type found Successfully.-----\n");
	}
	else {
		printf("\n-----Failed to get user home folder type.-----\n");
	}

	tag_t create_input;
	status = TCTYPE_construct_create_input(type, &create_input);
	if (status == ITK_ok) {
		printf("\n-----Input created Successfully.-----\n");
	}
	else {
		printf("\n-----Failed to create input.-----\n");
	}

	int AOM_set_value_string(create_input, "object_name", "Folder by ITK");
	if (status == ITK_ok) {
		printf("\n-----String set on Input Successfully.-----\n");
	}
	else {
		printf("\n-----Failed to set string onInput.-----\n");
	}

	tag_t new_folder = NULLTAG;
	status= TCTYPE_create_object(create_input, &new_folder);
	if (status == ITK_ok) {
		printf("\n-----New folder created Successfully.-----\n");
	}
	else {
		printf("\n-----Failed to create new folder.-----\n");
	}

	status = AOM_save_with_extensions(new_folder);	
	if (status == ITK_ok) {
		printf("Folder saveded Successful.\n");
	}
	else {
		printf("Failed to save folder.\n");
	}

	status = ITK_exit_module(true); // log out fro teamcenter
	if (status == ITK_ok) {
		printf("\n-----Login-out Successful.-----\n");
	}
	else {
		printf("\n-----Failed to Login-out.-----\n");
	}
	
	(void)_getch();
	return ITK_ok;
}
