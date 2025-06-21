# Alarme-De-Incendio-Inclusivo-
Criado por: Alessandro da Rosa, Arthur B. Spada, Gabriel Andrioli, Guilherme Castellani, Maria E. Schulze e Mariana Melara

Este projeto é um alarme de incêndio inclusivo, pensado para ambientes como hospitais ou clínicas, onde o alerta precisa ser adaptado para diferentes sensibilidades sensoriais, como em pacientes neurodivergentes, com TEA, esquizofrenia, ansiedade ou até mesmo com demência, Um alarme tradicional pode causar crises graves nesses públicos — por isso, esse sistema aposta em alertas mais suaves e previsíveis, com sinalização visual e sonora adaptadas.

O sistema utiliza LEDs com efeito visual suave (fade), buzzers com frequências variadas e um display LCD informativo, tornando o alarme mais acessível e menos agressivo para quem é sensível a estímulos sonoros ou visuais intensos.

Objetivo:
Desenvolver um sistema de alarme de incêndio adaptado às necessidades de pacientes sensíveis a sons, luzes ou mudanças bruscas, garantindo segurança e conforto durante emergências.

Público-Alvo:
Pacientes com Transtorno do Espectro Autista (TEA)
Pessoas com transtornos de ansiedade ou esquizofrenia
Pacientes em unidades psiquiátricas
Idosos com demência
Crianças em unidades pediátricas

Problema dos Alarmes Convencionais:
Sons agudos → provocam crises de ansiedade
Luzes piscantes → desorientação ou reações imprevisíveis
Falta de previsibilidade → eleva o estresse e a insegurança

Soluções Técnicas Propostas:
Alarmes Sonoros Adaptados
Frequência de 520 Hz, mais tolerável para o ouvido sensível
Sinalização Visual Inclusiva
LEDs com efeito fade e cores suaves (como verde e azul)
Evita piscadas rápidas, apostando em transições suaves
Comunicação Visual
Display LCD com mensagens claras e diretas, como “ALERTA DE INCÊNDIO”

Componentes Utilizados:
Arduino Uno
Display LCD 16x2
LEDs (vermelhos e verdes)
Potenciômetro (para controle do LCD)
3 Botões
3 Buzzers
Jumpers e Protoboard

O sistema possui 3 modos de alerta, ativados por botões:

Botão 1 – Alarme Principal (Sala de Espera)
Ativa:
LCD com mensagem “ALERTA DE INCÊNDIO”
Buzzer na frequência de 520Hz
LED com efeito fade suave
Ideal para alertar sem causar pânico imediato.

Botão 2 – Alerta Imediato (Hipersensibilidade auditiva)
Ativa:
LED vermelho (sem fade)
Buzzer 520Hz
Alerta mais direto, útil para situações de emergência onde a atenção precisa ser rápida.

Botão 3 – Alerta Suave (Hipersensibilidade visual)
Ativa:
LED verde com efeito fade
Buzzer comum (ligado/desligado)
Indicado para pacientes sensíveis a sons ou luzes intensas.

O código está todo escrito em Arduino C++, e utiliza as bibliotecas LiquidCrystal para o LCD e tone() para controle dos buzzers.
