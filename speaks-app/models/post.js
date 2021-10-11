'use strict';
const {
  Model
} = require('sequelize');
module.exports = (sequelize, DataTypes) => {
  class Post extends Model {
    /**
     * Helper method for defining associations.
     * This method is not a part of Sequelize lifecycle.
     * The `models/index` file will call this method automatically.
     */
    static associate(models) {
      // define association here
      Post.belongsTo(models.User, { foreignKey: 'UserId' })
      Post.hasMany(models.Favorite, { foreignKey: 'PostId' })
    }
  };
  Post.init({
    title: {
      type: DataTypes.STRING,
      allowNull: false,
      validate: {
        notNull: {
          msg: 'Title cannot be empty/null!'
        },
        notEmpty: {
          msg: 'Title cannot be empty/null!'
        }
      }
    },
    description: {
      type: DataTypes.STRING,
      allowNull: false,
      validate: {
        notNull: {
          msg: 'Description cannot be empty/null!'
        },
        notEmpty: {
          msg: 'Description cannot be empty/null!'
        }
      }
    },
    img_url: {
      type: DataTypes.STRING,
      allowNull: false,
      validate: {
        notNull: {
          msg: 'Image cannot be empty/null!'
        },
        notEmpty: {
          msg: 'Image cannot be empty/null!'
        }
      }
    },
    UserId: {
      type: DataTypes.INTEGER,
      allowNull: false,
      validate: {
        notNull: {
          msg: 'Re-login required!'
        },
        notEmpty: {
          msg: 'Re-login required!'
        }
      }
    }
  }, {
    sequelize,
    modelName: 'Post',
  });
  return Post;
};