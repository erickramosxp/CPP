#!/bin/bash

# Função que executa um teste
test_case() {
  INPUT=$1
  EXPECTED_CHAR=$2
  EXPECTED_INT=$3
  EXPECTED_FLOAT=$4
  EXPECTED_DOUBLE=$5

  echo -e "\n== Testando input: \"$INPUT\" =="

  # Executa o programa e armazena a saída
  OUTPUT=$(./convert "$INPUT")

  # Verificações
  PASS=true

  # Verifica CHAR
  if echo "$OUTPUT" | grep -q "char: $EXPECTED_CHAR"; then
    echo "[OK] char: $EXPECTED_CHAR"
  else
    echo "[FAIL] char esperado: $EXPECTED_CHAR"
    echo "       Saída real:"
    echo "$OUTPUT" | grep "char:"
    PASS=false
  fi

  # Verifica INT
  if echo "$OUTPUT" | grep -q "int: $EXPECTED_INT"; then
    echo "[OK] int: $EXPECTED_INT"
  else
    echo "[FAIL] int esperado: $EXPECTED_INT"
    echo "       Saída real:"
    echo "$OUTPUT" | grep "int:"
    PASS=false
  fi

  # Verifica FLOAT
  if echo "$OUTPUT" | grep -q "float: $EXPECTED_FLOAT"; then
    echo "[OK] float: $EXPECTED_FLOAT"
  else
    echo "[FAIL] float esperado: $EXPECTED_FLOAT"
    echo "       Saída real:"
    echo "$OUTPUT" | grep "float:"
    PASS=false
  fi

  # Verifica DOUBLE
  if echo "$OUTPUT" | grep -q "double: $EXPECTED_DOUBLE"; then
    echo "[OK] double: $EXPECTED_DOUBLE"
  else
    echo "[FAIL] double esperado: $EXPECTED_DOUBLE"
    echo "       Saída real:"
    echo "$OUTPUT" | grep "double:"
    PASS=false
  fi

  if $PASS; then
    echo "✅ Resultado: PASS"
  else
    echo "❌ Resultado: FAIL"
  fi
}

test_invalid_case() {
  local input=$1
  local expected="$2"

  output=$(./convert "$input")
  if [ "$output" = "$expected" ]; then
    echo "✅ Test with input '$input' passed."
  else
    echo "❌ Test with input '$input' failed."
    echo "   Expected: $expected"
    echo "   Got:      $output"
  fi
}

# Lista de testes
test_case "B" "'B'" "66" "66.0f" "66.0"
test_case "42" "'*'" "42" "42.0f" "42.0"
test_case "3.14" "Non displayable" "3" "3.14f" "3.14"
test_case "nan" "impossible" "impossible" "nanf" "nan"
test_case "+inf" "impossible" "impossible" "+inff" "+inf"
test_case "-inff" "impossible" "impossible" "-inff" "-inf"
test_case "127" "Non displayable" "127" "127.0f" "127.0"
test_case "256" "impossible" "256" "256.0f" "256.0"
test_case "0" "Non displayable" "0" "0.0f" "0.0"
test_case "31" "Non displayable" "31" "31.0f" "31.0"
test_case "32" "' '" "32" "32.0f" "32.0"
# test_case "0.0000001" "Non displayable" "0" "1e-07f" "1e-07"
# test_case "3.14159265358979323846" "Non displayable" "3" "3.1415927410f" "3.141592653589793"
test_case "-42" "impossible" "-42" "-42.0f" "-42.0"
test_invalid_case "hello" "This is not a literal value"
test_case "'" "'''" "39" "39.0f" "39.0"


