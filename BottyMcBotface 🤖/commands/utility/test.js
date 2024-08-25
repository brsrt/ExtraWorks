const { SlashCommandBuilder } = require("discord.js");

module.exports = {
  data: new SlashCommandBuilder()
    .setName("user")
    .setDescription("Collects user input of various types")
    .addStringOption((option) =>
      option
        .setName("username")
        .setDescription("Enter your username")
        .setRequired(true)
    )
    .addIntegerOption((option) =>
      option.setName("age").setDescription("Enter your age").setRequired(true)
    )
    .addBooleanOption((option) =>
      option
        .setName("subscribe")
        .setDescription("Are you subscribed?")
        .setRequired(true)
    )
    .addUserOption((option) =>
      option
        .setName("target")
        .setDescription("Select a user")
        .setRequired(false)
    )
    .addChannelOption((option) =>
      option
        .setName("channel")
        .setDescription("Select a channel")
        .setRequired(false)
    )
    .addRoleOption((option) =>
      option.setName("role").setDescription("Select a role").setRequired(false)
    )
    .addMentionableOption((option) =>
      option
        .setName("mentionable")
        .setDescription("Select something mentionable (user/role)")
        .setRequired(false)
    )
    .addNumberOption((option) =>
      option
        .setName("rating")
        .setDescription("Rate your experience from 1 to 10")
        .setRequired(false)
    )
    .addAttachmentOption((option) =>
      option
        .setName("attachment")
        .setDescription("Attach a file")
        .setRequired(false)
    ),

  async execute(interaction) {
    // Collect the inputs
    const username = interaction.options.getString("username");
    const age = interaction.options.getInteger("age");
    const subscribe = interaction.options.getBoolean("subscribe");
    const target = interaction.options.getUser("target");
    const channel = interaction.options.getChannel("channel");
    const role = interaction.options.getRole("role");
    const mentionable = interaction.options.getMentionable("mentionable");
    const rating = interaction.options.getNumber("rating");
    const attachment = interaction.options.getAttachment("attachment");

    // Create a response message
    let response = `**User Info**\nUsername: ${username}\nAge: ${age}\nSubscribed: ${
      subscribe ? "Yes" : "No"
    }`;

    if (target) response += `\nTarget User: ${target.tag}`;
    if (channel) response += `\nChannel: ${channel.name}`;
    if (role) response += `\nRole: ${role.name}`;
    if (mentionable) response += `\nMentionable: ${mentionable}`;
    if (rating !== null) response += `\nRating: ${rating}`;
    if (attachment) response += `\nAttachment: ${attachment.name}`;

    // Reply to the interaction
    await interaction.reply({ content: response, ephemeral: true });
  },
};
