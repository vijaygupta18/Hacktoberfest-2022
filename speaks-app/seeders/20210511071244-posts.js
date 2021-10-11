'use strict';

module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('Posts', [{
      title: "whohooooo",
      description: "I win agains Thor today.. :)",
      img_url: "https://i.imgflip.com/30jhaa.jpg",
      UserId: 1,
      createdAt: new Date(),
      updatedAt: new Date()
    }], {});

  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.bulkDelete('Posts', null, {});
  }
};