CC=gcc
SOURCE_FILE=main.c
OUTPUT_FILE=creator


make:
	$(CC) $(SOURCE_FILE) -o $(OUTPUT_FILE)

clean:
	rm -rf $(OUTPUT_FILE)

clean_created:
	rm -rf src include assets

run:
	./$(OUTPUT_FILE)