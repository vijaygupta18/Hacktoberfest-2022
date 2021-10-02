<template>
  <div>
    <div class="mx-auto my-auto relative pt-0 sm:px-6 lg:px-8 max-w-lg">
      <nav class="flex items-center justify-between sm:h-10 lg:justify-start" aria-label="Global">
        <div class="flex items-center flex-grow flex-shrink-0 lg:flex-grow-0">
          <div class="flex items-center justify-between w-full md:w-auto">
            <router-link class="sr-only" to="/"></router-link>
          </div>
        </div>
      </nav>

      <router-view></router-view>
    </div>
  </div>
</template>

<script>
export default {
  name: 'App',
  data: () => ({
    //
  }),
};
</script>
