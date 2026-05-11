# Detection Summary

## YARA Detection

Se desarrolló una regla YARA personalizada para detectar el
binario educativo `team5_payload.exe`.

La regla identifica múltiples indicadores asociados con el
comportamiento ofensivo controlado como lo son:

- ejecución de PowerShell codificado
- uso de APIs sospechosas
- comunicación localhost
- ejecución de procesos
- strings específicas del menú interactivo

La regla detectó exitosamente el binario durante las pruebas.

---

## CAPA Analysis

CAPA fue utilizado para identificar capacidades ofensivas
simuladas dentro del binario.

El análisis detectó correctamente:

- comunicación HTTP
- conexión a URL
- ejecución de comandos
- creación de procesos
- asignación de memoria RWX
- interacción con procesos

Estas capacidades coinciden directamente con las técnicas
implementadas en el proyecto, incluyendo el stager local,
PowerShell codificado y simulación de inyección en memoria.

La técnica de descifrado XOR no fue detectada explícitamente
por CAPA debido a la simplicidad de su implementación, aunque
sí pudo observarse manualmente durante el análisis estático y
dinámico.
