const { Events } = require('discord.js');

module.exports = {
	name: Events.ClientReady,
	once: true,
	execute(client) {
		console.log(`Ready! Logged in as ${client.user.tag}`);

		// Array of humorous activities with corresponding statuses
		let presences = [
			{ activities: [{ name: 'with a rubber duck', type: 0 }], status: 'online' },
			{ activities: [{ name: 'Minecraft in real life', type: 0 }], status: 'idle' },
			{ activities: [{ name: 'hide and seek with the FBI', type: 0 }], status: 'dnd' },
			{ activities: [{ name: 'where’s Waldo?', type: 3 }], status: 'online' },
			{ activities: [{ name: 'AI take over the world', type: 2 }], status: 'dnd' },
			{ activities: [{ name: 'banana peel jokes', type: 2 }], status: 'idle' },
			{ activities: [{ name: 'invisible chess', type: 0 }], status: 'online' },
			{ activities: [{ name: 'with a time machine', type: 0 }], status: 'dnd' },
			{ activities: [{ name: 'prank calls to the moon', type: 0 }], status: 'idle' },
			{ activities: [{ name: 'a staring contest with itself', type: 0 }], status: 'online' },
			{ activities: [{ name: 'life on Mars', type: 3 }], status: 'dnd' },
			{ activities: [{ name: 'alien conspiracy theories', type: 2 }], status: 'online' },
			{ activities: [{ name: 'a never-ending loading screen', type: 3 }], status: 'idle' },
			{ activities: [{ name: 'how to speak whale', type: 2 }], status: 'dnd' },
			{ activities: [{ name: 'outsmarting Sherlock Holmes', type: 0 }], status: 'online' },
			{ activities: [{ name: 'teleportation fails', type: 3 }], status: 'idle' },
		];

		let i = 0;

		// Set an interval to change the activity and status every 10 seconds
		setInterval(() => {
			client.user.setPresence({
				activities: presences[i].activities,
				status: presences[i].status,
			});
			i = (i + 1) % presences.length; // Cycle through presences
		}, 10000); // Change every 10 seconds
	},
};
