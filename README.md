# Desarrollo de plataforma de simulación para la comunicación entre vehículos
El proyecto consiste en el desarrollo de unos robots capaces de seguir líneas utilizando sensores de reflexión. Haciendo uso de un sensor de infrarojos los robots evitarán chocarse en todo momento. Al mismo tiempo estos robots compartirán datos como: velocidad, posición, batería restante, etc.

Para la comunicación entre los robots se utilizará la tecnología Bluetooth 4.0, ya que permite transferencias a altas velocidades.

En la parte superior de la plataforma se dispondrá una cámara para localizar a los diferentes robots mediante procesamiento de imagenes, cada uno de ellos será identificado mediante un color o una figura.

Tanto en los robots como en el sistema de localización, se hará uso de un sistema embebido basado en GNU/Linux, basado en la arquitectura ARM. En un futuro, los robots deberán simular distintas situaciones y modos establecidos a través de comandos.
