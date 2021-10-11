'use strict';

module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('Users', [{
      email: "noobmaster@mail.com",
      username: "noobmaster",
      password: "$2a$04$7YELo9fNEhYfYvxklzu1f.0H6g.KU6zmWqByYwMW5zWi16TEtd9Uq", //winner999
      createdAt: new Date(),
      updatedAt: new Date()
    }, {
      email: "adastariana@gmail.com",
      username: "anggidast",
      password: "$2a$04$hAGmz24.3CB0XqZUdaL3c.N9UK8kVM6iHRAMw7Oe2wEDnGFWL4h1a",
      createdAt: new Date(),
      updatedAt: new Date()
    }], {})
  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.bulkDelete('Users', null, {});
  }
};