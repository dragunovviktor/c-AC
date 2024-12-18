#!/bin/bash

# Запуск контейнеров с помощью docker-compose
echo "Starting containers using docker-compose..."
docker-compose up -d


echo "Database is ready."

# Запуск миграций
echo "Running migrations..."
flask db upgrade

# Запуск Flask приложения
echo "Starting the Flask application..."
python app.py
