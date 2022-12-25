#include <mongoc/mongoc.h>
#include <bson/bson.h>
#include <stdio.h>


int main (int ac, char** av) {
    // uri here
mongoc_uri_t *uri;
mongoc_database_t *database;
mongoc_client_t *client;
mongoc_collection_t *collection;
bson_t *command, reply, *insert, *doc;
bson_error_t error;
bson_oid_t oid;
char *str;
bool retval;

mongoc_init ();

uri = mongoc_uri_new_with_error (uri_string, &error);

if (!uri) {
    fprintf (stderr, 
        "failed to parse URI: %s\n"
        "error message: %s\n",
        uri_string,
        error.message);
        return EXIT_FAILURE;
}

// Create new client instance
client = mongoc_client_new_from_uri(uri);
if(!client) {
    return EXIT_FAILURE;
}

mongoc_client_set_appname (client, "connect-example");

// Get a handle on the database and collection
database = mongoc_client_get_database (client, "animals");
collection = mongoc_client_get_collection (client, "animals", "animals");

doc = bson_new ();
bson_oid_init (&oid, NULL);
BSON_APPEND_OID(doc, "_id", &oid);
BSON_APPEND_UTF8(doc, "Cat", "Pepper");

// command = BCON_NEW ("ping", BCON_INT32(1));

// retval = mongoc_client_command_simple (
//     client, "admin", command, NULL, &reply, &error);

// if (!retval) {
//     fprintf (stderr, "%s\n", error.message);
//     return EXIT_FAILURE;
// }

// str = bson_as_json (&reply, NULL);
// printf("%s\n", str);

// insert = BCON_NEW ("hello", BCON_UTF8 ("world"));

// if (!mongoc_collection_insert_one (collection, insert, NULL, NULL, &error)) {
//     fprintf(stderr, "%s\n", error.message);
// }
if (!mongoc_collection_insert_one (collection, doc, NULL, NULL, &error)) {
    fprintf(stderr, "%s\n", error.message);
}

// bson_destroy(insert);
bson_destroy(doc);
// bson_destroy(&reply);
// bson_destroy(command);
// bson_free(str);

mongoc_collection_destroy(collection);
mongoc_database_destroy (database);
mongoc_uri_destroy(uri);
mongoc_client_destroy (client);

mongoc_cleanup ();

return 0;

}



// gcc -o mongo mongo.c $(pkg-config --libs --cflags libmongoc-1.0)