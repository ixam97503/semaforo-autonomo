# Sistema de Medición de Distancia con Sensor Ultrasonido y LCD

## Descripción del Proyecto
Este proyecto implementa un sistema de medición de distancia utilizando un sensor ultrasonido HC-SR04, una pantalla LCD I2C y LEDs/buzzer para proporcionar indicaciones visuales y auditivas. El sistema mide la distancia a un objeto y muestra el resultado en la pantalla LCD, mientras que los LEDs y el buzzer cambian de estado según el rango de distancia detectado.

## Componentes Utilizados
- **Sensor Ultrasonido HC-SR04**: Para medir la distancia.
- **Pantalla LCD I2C (16x2)**: Para mostrar la distancia en tiempo real.
- **LEDs (Verde, Amarillo, Rojo)**: Indicadores visuales basados en la distancia.
- **Buzzer**: Indicador auditivo.
- **Arduino**: Plataforma de desarrollo utilizada.

## Funcionamiento
1. **Medición de Distancia**:
   - El sensor ultrasonido envía un pulso de sonido y calcula el tiempo que tarda en recibir el eco.
   - La distancia se calcula utilizando la fórmula:  
     \[
     \text{Distancia (cm)} = \frac{\text{Duración (µs)} \times 0.034}{2}
     \]

2. **Indicadores Visuales y Auditivos**:
   - **Distancia > 8 cm**: LED Verde encendido, Buzzer activo.
   - **Distancia entre 4 cm y 8 cm**: LED Amarillo encendido, Buzzer activo durante 1 segundo.
   - **Distancia ≤ 4 cm**: LED Rojo encendido, Buzzer desactivado.

3. **Visualización en Pantalla LCD**:
   - La distancia medida se muestra en tiempo real en la pantalla LCD.

## Conexiones
- **Sensor Ultrasonido**:
  - `Trigger` → Pin 26
  - `Echo` → Pin 27
- **LEDs**:
  - Verde → Pin 22
  - Amarillo → Pin 23
  - Rojo → Pin 24
- **Buzzer** → Pin 25
- **Pantalla LCD I2C** → Dirección 0x27 (ajustar si es necesario)

## Notas
- Asegúrese de instalar la biblioteca `LiquidCrystal_I2C` en su entorno de Arduino.
- Verifique la dirección I2C de su pantalla LCD utilizando un escáner I2C si es necesario.
