# Użyj oficjalnego obrazu Dockera z GCC jako bazowy
FROM gcc:latest

# Ustaw katalog roboczy w kontenerze
WORKDIR /app

# Skopiuj pliki projektu do katalogu roboczego
COPY . .

# Skonfiguruj i zbuduj aplikację
RUN mkdir build && cd build && cmake .. && make

# Wskazanie komendy uruchamianej po starcie kontenera
CMD ["./build/your_executable_name"]
