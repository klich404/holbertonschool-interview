#!/usr/bin/node
if (process.argv.length !== 3) {
    console.log('Usage: ./0-starwars_characters.js <film number>');
  } else {
    getCharactersInOrder(process.argv[2], 'https://swapi.co/api/people/');
  }
  
  function getCharactersInOrder (filmID, chURL) {
    const request = require('request');
    request(chURL, function (error, response, body) {
      if (error) {
        console.error(error);
      } else {
        const json = JSON.parse(body);
        chURL = json.next;
        const characters = json.results;
        characters.forEach(function (character) {
          const films = character.films;
          films.forEach(function (film) {
            if (film.includes(filmID)) {
              console.log(character.name);
            }
          });
        });
      }
      if (chURL !== null) {
        getCharactersInOrder(filmID, chURL);
      }
    });
  }