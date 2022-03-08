#include <stdio.h>
#include "cJSON.h"

int main()
{
	int arr_buf[] = {1,2,3,4,5};
	int arr_len = sizeof(arr_buf) / sizeof(*arr_buf);
	cJSON* json = cJSON_CreateObject();
	
	cJSON_AddItemToObject(json,"age", cJSON_CreateNumber(20));

	cJSON* json2 = cJSON_CreateObject();
	cJSON_AddItemToObject(json2, "name", cJSON_CreateString("ÕÅÈý"));
	cJSON_AddItemToObject(json, "person", json2);
	printf("%s\r\n", cJSON_PrintUnformatted(json));
	
	cJSON* json_root = cJSON_Parse(cJSON_PrintUnformatted(json));
	cJSON_Delete(json);
	cJSON* age, * name;
	age = cJSON_GetObjectItem(json_root,"age");
//	name = cJSON_GetObjectItem(json_root,"name");

	printf("name is ,age is %d\r\n",age->valueint);
//	cJSON_Delete(json_root);

	return 0;
}