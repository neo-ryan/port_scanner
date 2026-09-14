# 🔍 C Port Scanner

Um port scanner TCP básico feito em C puro de baixo nível usando BSD Sockets nativos do Linux. 

Feito pra não dormir nas aulas de C da faculdade, mas totalmente funcional.

## 🚀 O que este projeto faz?

- Varre portas TCP sequenciais (1 a 100 por padrão) via chamadas de sistema.
- Manipula endereços IPv4 (`struct sockaddr_in`) e converte byte order de rede (*Big-Endian*) usando `htons`.
- Identifica portas abertas tentando realizar a primeira etapa do handshake TCP (`connect()`).

## 🛠️ Como compilar e rodar

Exige apenas um compilador C (`gcc` ou `clang`) e um sistema POSIX (Linux, WSL ou macOS).

```bash
# 1. Clona o repositório (ou salva o arquivo scanner.c)
git clone https://github.com/neo-ryan/port_scanner.git
cd c-port-scanner

# 2. Compila com o GCC
gcc port_scanner.c -o scanner

# 3. Executa passando um IP de alvo
./scanner 127.0.0.1
```
## ⚠️ Disclaimer

Projeto exclusivamente didático desenvolvido para entender arquitetura de redes, manipulação de memória e programação de sockets em C. Não use contra IPs que não sejam de sua propriedade.
