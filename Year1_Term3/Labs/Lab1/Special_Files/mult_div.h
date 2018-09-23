struct mult_div_values {
	int mult;
	float div;
};

mult_div_values** create_table(int m, int n);
bool is_valid_dimensions(char *m, char *n);
bool is_int (char* num);
char* get_input(); 
void add_one_char(char** str, char c);
void set_mult_values(mult_div_values **table, int m, int n);
void set_div_values(mult_div_values **table, int m, int n);
void delete_table(mult_div_values **table, int m);
void print_mult(mult_div_values **table, int m, int n);
void print_div(mult_div_values **table, int m, int n);
bool run_again();


