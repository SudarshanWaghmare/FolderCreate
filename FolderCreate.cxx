#include"FolderCreate.hxx"

int ITK_user_main(int argc,	char* argv[]) {

	printf("\n-----Utility Started.-----\n");

	int status;
	/*char* user = ITK_ask_cli_argument("-u=");
	char* password = ITK_ask_cli_argument("-p=");
	char* group = ITK_ask_cli_argument("-g=");*/		

	status = ITK_init_module("infodba", "infodba", "dba");
	if (status == ITK_ok) {
		printf("\n-----Login Successful.-----\n");
	}
	else {
		printf("\n-----Failed to Login.-----\n");
	}	

	tag_t Fuser = NULLTAG;
	tag_t Uhome_folder = NULLTAG;
	tag_t type = NULLTAG;
	tag_t create_input = NULLTAG;
	tag_t new_folder = NULLTAG;
	
	status = TCTYPE_ask_type("Folder", &type);
	
	status = TCTYPE_construct_create_input(type, &create_input);
	
	status = AOM_set_value_string(create_input, "object_name", "Folder by ITK_1");
		
	status = TCTYPE_create_object(create_input, &new_folder);	

	status = AOM_save_with_extensions(new_folder);	

	status = SA_find_user2("infodba", &Fuser);

	status = SA_ask_user_home_folder(Fuser, &Uhome_folder);
	
	status = FL_insert(Uhome_folder, new_folder, 999);

	status = AOM_save_with_extensions(Uhome_folder);

	status = ITK_exit_module(true); 

	printf("\n-----Utility execuated Successful.-----\n");

	(void)_getch();
	return status;
}
